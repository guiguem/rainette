#ifndef CARDDATA_H
#define CARDDATA_H

#include <string>
#include <iostream>
#include <vector>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>

struct CardData{

public:

  int scintID;
  //std::vector<int> scintID;
  std::vector<int> Time;
  
private:
friend class boost::serialization::access;
  
  template<class Archive> void serialize(Archive & ar, const unsigned int version){
    
    ar & scintID;
    ar & Time;
    
  }

};

#endif
