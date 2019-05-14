#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"
// #include "MyDataModel.h"
class MyDataModel;

class TextReader : public Tool::Registrar<TextReader>
{
  public:
    TextReader(std::string x) : m_x(x) {}

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
