#ifndef MYDATAMODEL_H
#define MYDATAMODEL_H

#include <map>
#include <string>
#include <vector>

//#include "TTree.h"

#include "DataModel.h"
#include "Store.h"
#include "Logging.h"

#include <zmq.hpp>

class MyDataModel : public DataModel{


 public:
  
  MyDataModel();
  //TTree* GetTTree(std::string name);
  //void AddTTree(std::string name,TTree *tree);
  //void DeleteTTree(std::string name,TTree *tree);

  Store vars;
  Logging *Log;

  zmq::context_t* context;


  //  bool (*Log)(std::string, int);

  /*  
  template<Type T>
    struct Log {
      typedef bool (*type)(T message,int verboselevel);
    };
  */
 private:


  
  //std::map<std::string,TTree*> m_trees; 
  
  
  
};



#endif
