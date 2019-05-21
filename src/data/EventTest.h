#ifndef EventTest_H_
#define EventTest_H_

#include <iostream>
#include <string>

#include "SerialisableObject.h"

// class EventTest : public SerialisableObject
// {
//     friend class boost::serialization::access;

// public:
//     double aValue;
//     double bValue;

//     bool Print()
//     {
//         std::cout << "aValue : " << aValue << std::endl;
//         std::cout << "bValue : " << bValue << std::endl;
//         return true;
//     };

//     // std::string ConvertDataToString();

//     template <class Archive>
//     void serialize(Archive &ar, const unsigned int version)
//     {
//         if (serialise)
//         {
//             ar &aValue;
//             ar &bValue;
//         }
//     }
// };

#endif