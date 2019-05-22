#ifndef TestObj_H_
#define TestObj_H_

#include <iostream>      // for ostream, string, ostringstream
#include "BoostStore.h"  // for BoostStore
namespace boost { namespace serialization { class access; } }

class TestObj : public SerialisableObject::Registrar<TestObj>
{

    friend class boost::serialization::access;

public:
    TestObj(std::string name) : aValue(0), bValue(0) { serialise = true; }
    TestObj(std::string name, double theaValue, double thebValue) : aValue(theaValue), bValue(thebValue) { serialise = true; }

    inline double GetA() const { return aValue; }
    inline double GetB() const { return bValue; }

    inline void SetA(double tc) { aValue = tc; }
    inline void SetB(double chg) { bValue = chg; }

    bool Print()
    {
        std::cout << "aValue : " << aValue << std::endl;
        std::cout << "bValue : " << bValue << std::endl;
        return true;
    }
    // Needed so we can write it into a text file (via TextWriterTool)
    friend std::ostream &operator<<(std::ostream &out, const TestObj &obj);
    // friend void &operator>>(std::ostream &out, TestObj obj);

protected:
    double aValue;
    double bValue;

    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        if (serialise)
        {
            ar &aValue;
            ar &bValue;
        }
    }
};

std::ostream &operator<<(std::ostream &out, const TestObj &obj)
{
    out << obj.aValue << "\t" << obj.bValue << std::endl;
    return out;
}


#endif