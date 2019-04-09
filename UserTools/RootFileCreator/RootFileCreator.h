#ifndef ROOTFILECREATOR_H
#define ROOTFILECREATOR_H

#include <string>
#include <iostream>

#include "Tool.h"

class MyDataModel;

class RootFileCreator : public Tool::Registrar<RootFileCreator>
{
  public:
    RootFileCreator(std::string x) : m_x(x) {}

  public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

  private:
    int m_verbose;
    std::string m_x;

};

#endif
