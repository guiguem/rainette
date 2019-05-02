#ifndef ROOTFILEMANAGER_H
#define ROOTFILEMANAGER_H

#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1.h>

#include "Tool.h"

class MyDataModel;

class RootFileManager : public Tool::Registrar<RootFileManager>
{
  public:
    RootFileManager(std::string x) : m_x(x) {}

  public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

  private:
    int m_verbose;
    std::string m_x;
    TFile* foutput;

};

#endif
