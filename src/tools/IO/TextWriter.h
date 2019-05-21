#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"
// #include "RainetteDataModel.h"
class RainetteDataModel;


class TestObject : public SerialisableObject
{

    friend class boost::serialization::access;

public:
    double aValue;
    double bValue;

    bool Print()
    {
        std::cout << "aValue : " << aValue << std::endl;
        std::cout << "bValue : " << bValue << std::endl;
        return true;
    }

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


class TextWriter : public Tool::Registrar<TextWriter>
{
public:
    TextWriter(std::string x) : m_x(x) {}

public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

private:
    int m_verbose;
    std::string m_x;
    std::string m_filename;
    std::ofstream m_file;

};

#endif
