#ifndef TestObj_H_
#define TestObj_H_

#include "SerialisableObject.h"

class TestObj : public SerialisableObject
{

    friend class boost::serialization::access;

public:
    TestObj() : aValue(0), bValue(0) { serialise = true; }
    TestObj(double theaValue, double thebValue) : aValue(theaValue), bValue(thebValue) { serialise = true; }

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
    friend std::ostream &operator<<(std::ostream &out, const TestObj &obj);

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