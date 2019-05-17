#ifndef ROOTFILEMANAGER_H
#define ROOTFILEMANAGER_H

#include <string>
#include <iostream>
#include <TFile.h>
#include "TTree.h"

#include "Tool.h"
#include "RainetteDataModel.h"

class RainetteDataModel;

class RootFileManager : public Tool::Registrar<RootFileManager>
{
  public:
    RootFileManager(std::string x) : m_x(x) {}

  public:
    bool Initialise(std::string configfile, RainetteDataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

  private:
    int m_verbose;
    std::string m_x;
    TFile* foutput;
    CardData localcard;

};

#endif
