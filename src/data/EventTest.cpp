#include "EventTest.h"

#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

// bool EventTest::Print()
// {
//     std::cout << "aValue : " << aValue << std::endl;
//     std::cout << "bValue : " << bValue << std::endl;
//     return true;
// }

// std::string EventTest::ConvertDataToString()
// {
//     std::string returnedString;
//     returnedString += boost::lexical_cast<std::string>(aValue) + "\t " + boost::lexical_cast<std::string>(bValue);

//     boost::char_separator<char> sep{"\t"};
//     boost::tokenizer<boost::char_separator<char>> tok{returnedString, sep};
//     for (const auto &beg : tok)
//     {
//         std::cout << beg << "\n";
//     }
//     return returnedString;
// };
