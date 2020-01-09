#ifndef ROOTFILEMANAGER_H
#define ROOTFILEMANAGER_H

#include <string>
#include <iostream>
#include <TFile.h>
#include "TTree.h"

#include "CardData.h"
#include "Tool.h"

class RootFileManager : public Tool::Registrar<RootFileManager>
{
  public:
    RootFileManager(std::string x) : m_x(x) {}

  public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

  private:
    bool PrepareBranches();

  private:
    int m_verbose;
    std::string m_x;
    TFile* foutput;
    CardData localcard;

};

#endif
