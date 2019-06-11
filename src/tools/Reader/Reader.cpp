/* Author Benjamin Richards (b.richards@qmul.ac.uk) */

#include "Reader.h"

Reader::Reader():Tool(){}


bool Reader::Initialise(std::string configfile, DataModel &data){

  /////////////////// Usefull header ///////////////////////
  if(configfile!="")  m_variables.Initialise(configfile); //loading config file
  //m_variables.Print();

  m_data= &data; //assigning transient data pointer
  /////////////////////////////////////////////////////////////////

  if(!m_variables.Get("Verbosity", m_verbosity)) m_verbosity=0;
  if(!m_variables.Get("Reader_Receive_Wait", Reader_Receive_Wait)) Reader_Receive_Wait=100;
  if(!m_variables.Get("Reader_Quit_Wait", Reader_Quit_Wait)) Reader_Quit_Wait=1000;
  if(!m_variables.Get("Thread_Send_Wait", Thread_Send_Wait)) Thread_Send_Wait=200;
  if(!m_variables.Get("Data_Batch_Size", Data_Batch_Size)) Data_Batch_Size=100;
  
  IReader = new zmq::socket_t(*(m_data->context), ZMQ_PAIR);
  IReader->bind("inproc://ListenThread");
  
  args=new Listen_thread_args(m_data->context, Thread_Send_Wait, Data_Batch_Size);
  
  pthread_create (&thread, NULL, Reader::ListenThread, args);
  
  initems[0].socket = *IReader;
  initems[0].fd = 0;
  initems[0].events = ZMQ_POLLIN;
  initems[0].revents =0;

  outitems[0].socket = *IReader;
  outitems[0].fd = 0;
  outitems[0].events = ZMQ_POLLOUT;
  outitems[0].revents =0;

  return true;
}


bool Reader::Execute(){

  zmq::poll(&initems[0], 1, Reader_Receive_Wait);

  if ((initems[0].revents & ZMQ_POLLIN)) {
    
    zmq::message_t message;

    if(IReader->recv(&message)){
      
      std::istringstream iss(static_cast<char*>(message.data()));
      long long unsigned int pointer;
      
      std::vector<double>* data;
      
      iss>>std::hex>>pointer;
      data=reinterpret_cast<std::vector<double>* >(pointer);

      //do something with your double vector.... probably write it to the data model with:
      // m_data->Data=data;

    }
    
    else{
      std::string msg="ERROR!!!: Reader Failed to receive Data Pointer";
      m_data->Log->Log(msg,0,m_verbosity);
      return false;
    }
    
  }
  
  return true;
}


bool Reader::Finalise(){

  zmq::poll(&outitems[0], 1, Reader_Quit_Wait);
  
  if ((outitems[0].revents & ZMQ_POLLOUT)) {  
    
    zmq::message_t message(5);
    snprintf ((char *) message.data(), 5, "%s", "QUIT");
    
    if(!IReader->send(message)){
      std::string msg="ERROR!!!: Reader Failed to send QUIT message";
      m_data->Log->Log(msg,0,m_verbosity);
      return false;
    }
    
  }
  
  else{
    std::string msg="ERROR!!!: Reader timed out sending QUIT message";
    m_data->Log->Log(msg,0,m_verbosity);
    
    return false;
    
  }  

  pthread_join(thread, NULL);
  
  delete IReader;
  IReader=0;
  
  delete args;
  args=0;  
  
  return true;
}

void* Reader::ListenThread(void* arg){
  
  Listen_thread_args* args= static_cast<Listen_thread_args*>(arg);
 
  zmq::socket_t IThread (*(args->context), ZMQ_PAIR);
  
  IThread.connect("inproc://ListenThread");

  int UDPSocket=0;

  ////Here you would define your socket and connect etc. I don know the details of your system so i leave that up to you.

  std::vector<double>* data=new std::vector<double>; //This is a vector to store the data you receive from your UDP port. Iv no idea what the format is so i assumed a double is recived per messsage.
  
  zmq::pollitem_t initems [] = {
    { IThread, 0, ZMQ_POLLIN, 0 },
    { NULL, UDPSocket, ZMQ_POLLIN, 0 }
  };

  zmq::pollitem_t outitems [] = {
    { IThread, 0, ZMQ_POLLOUT, 0 }
  };

  bool running=true;
  
  while (running){

    zmq::poll(&initems[0], 2, 0);

    if ((initems[0].revents & ZMQ_POLLIN)) {
   
    zmq::message_t comm;
   
    IThread.recv(&comm);
    running=false;

    }

    if ((initems[1].revents & ZMQ_POLLIN)) {

      //This is where you would write your code to receive a message from the socket and fill the data vector or other object. If assumed your data is a double per message but you can change this what what ever your data is.

      double UDPData=99; ///Fake data received by message
      data->push_back(UDPData);
      
      if(data->size() >= args->Data_Batch_Size){

	std::stringstream tmp;
	tmp<<data;

	zmq::message_t message(tmp.str().length()+1);
	snprintf ((char *) message.data(), tmp.str().length()+1 , "%s" ,tmp.str().c_str()) ;
	
	zmq::poll(&outitems[0], 1, args->Thread_Send_Wait);
	
	if((outitems[0].revents & ZMQ_POLLOUT)) IThread.send(message);
	  
	else pthread_exit(NULL);
  data=new std::vector<double>;     
      
      }

    }
  
  }

  data->clear(); 
  delete data;
  data=0;

  pthread_exit(NULL);
  
}
