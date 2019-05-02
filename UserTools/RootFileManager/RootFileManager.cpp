#include "RootFileManager.h"

bool RootFileManager::Initialise(std::string configfile, DataModel &data)
{

  foutput = new TFile("output.root","NEW"); 

  if (configfile != "")
    m_variables.Initialise(configfile);
  else
  {
    exit(1);
  }
  //m_variables.Print();

  m_data = &data;
  m_variables.Get("verbose", m_verbose);

  return true;
}

bool RootFileManager::Execute()
{

  TH1D* htest = new TH1D("htest","htest",100,0,0);
  htest->FillRandom("gaus",1000);
  htest->Write();

  m_data->Log->Log("test 2", 2, m_verbose);

  return true;
}

bool RootFileManager::Finalise()
{
  foutput->Close();
  return true;
}
