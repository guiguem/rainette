#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"
// #include "MyDataModel.h"
class MyDataModel;

class MyTool : public Tool::Registrar<MyTool>
{
  public:
    MyTool(std::string x) : m_x(x) {}

    void makeNoise(); // { std::cerr << "Cat: " << m_x << "\n"; }

  public:
    bool Initialise(std::string configfile, DataModel &data);
    bool Execute();
    bool Finalise();

  private:
    int m_verbose;
    std::string m_x;

};

#endif
