#ifndef RAINETTEDATAMODEL_H
#define RAINETTEDATAMODEL_H

#include <map>
#include <string>
#include <vector>

#include "TTree.h"

#include "DataModel.h"
#include "Store.h"
#include "Logging.h"

#include <zmq.hpp>

#include "CardData.h"


class RainetteDataModel : public DataModel{


 public:
  
  RainetteDataModel();
  TTree* GetTTree(std::string name);
  void AddTTree(std::string name,TTree *tree);
  void DeleteTTree(std::string name,TTree *tree);

  Store vars;
  Logging *Log;
  
  zmq::context_t* context;

  std::vector<CardData*> Cards; 
  long eventnum;

 private:
  
  std::map<std::string,TTree*> m_trees; 
  
  
  
};



#endif
