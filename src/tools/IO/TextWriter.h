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
    bool Execute();// = 0;
    bool Finalise() override;

    // virtual bool ExtractSaveObjects();

private:
    int m_verbose;
    std::string m_x;
    std::string m_filename;
    std::string m_objectname;
    std::string m_storename;
    std::ofstream m_file;
};

#endif
