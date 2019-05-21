#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"
#include "TestObj.h"
// #include "RainetteDataModel.h"
class RainetteDataModel;


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
