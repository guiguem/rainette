#ifndef TestObj_H_
#define TestObj_H_

#include <iostream>     // for ostream, string, ostringstream
#include <vector>       // for ostream, string, ostringstream
#include "BoostStore.h" // for BoostStore
#include "Factory.h" // for Factory
#include "SerialisableObject.h" // for BoostStore
namespace boost
{
namespace serialization
{
class access;
}
} // namespace boost

class TestObj : public SerialisableObject
{

    friend class boost::serialization::access;

public:
    TestObj() : aValue(0), bValue(0) { serialise = true; }
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
    // Needed so we can write it into a text file (via TextWriter)
    friend std::ostream &operator<<(std::ostream &out, const TestObj &obj);
    friend std::ostream &operator<<(std::ostream &out, std::vector<TestObj> &vector);
    // Needed so we can read it from a text file (via TextWriter)
    friend std::istream &operator>>(std::istream &in, TestObj &obj);
    // friend std::istream &operator>>(std::istream &out, std::vector<TestObj> &vector);

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

REGISTER_FACTORY(SerialisableObject,TestObj)


std::istream &operator>>(std::istream &in, TestObj &obj)
{
    in >> obj.aValue >> obj.bValue;
    return in;
}

std::ostream &operator<<(std::ostream &out, const TestObj &obj)
{
    out << obj.aValue << "\t" << obj.bValue << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, std::vector<TestObj> &avector)
{
    for (std::vector<TestObj>::iterator iter = avector.begin(); iter != avector.end(); ++iter)
    {
        out << (*iter).aValue << "\t" << (*iter).bValue << std::endl;
    }
    return out;
}



#endif