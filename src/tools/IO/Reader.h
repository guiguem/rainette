/* Simple Tool for reading an incomming data stream in a threaded continuous / dead timeless way 

Author Benjamin Richards (b.richards@qmul.ac.uk)

*/

#ifndef Reader_H
#define Reader_H

#include <string>
#include <iostream>
#include <vector>

#include "Tool.h"

struct Listen_thread_args
{

    Listen_thread_args(zmq::context_t *incontext, int inThread_Send_Wait, int inData_Batch_Size)
    {
        context = incontext;
        Thread_Send_Wait = inThread_Send_Wait;
        Data_Batch_Size = inData_Batch_Size;
    }

    zmq::context_t *context;
    int Thread_Send_Wait;
    int Data_Batch_Size;
};

//###############################################
/*!
 @class Reader
 @author B. Richards

 @brief
 @details
*/
class Reader:  public Tool::Registrar<Reader>
{

public:
    Reader();
    bool Initialise(std::string configfile, DataModel &data);
    bool Execute();
    bool Finalise();

private:
    int m_verbosity;

    zmq::socket_t *IReader;
    zmq::pollitem_t initems[1];
    zmq::pollitem_t outitems[1];

    static void *ListenThread(void *arg);
    pthread_t thread;
    Listen_thread_args *args;

    int Reader_Receive_Wait;
    int Reader_Quit_Wait;
    int Thread_Send_Wait;
    int Data_Batch_Size;
};

#endif
