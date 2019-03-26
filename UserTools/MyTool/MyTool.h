#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"
#include "MyDataModel.h"

class MyTool : public Tool
{

  public:
    MyTool();
    bool Initialise(std::string configfile, MyDataModel &data);
    bool Execute();
    bool Finalise();

  private:
};

#endif
