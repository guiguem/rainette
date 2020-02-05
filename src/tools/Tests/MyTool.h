#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Factory.h" // for Factory
#include "Tool.h"
#include "TestObj.h"


class RainetteDataModel;


class MyTool : public Tool
{
public:
    MyTool(){}
    MyTool(std::string x) : m_x(x) {}

public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

private:
    int m_verbose;
    std::string m_x;
};

REGISTER_FACTORY(Tool,MyTool)

#endif
