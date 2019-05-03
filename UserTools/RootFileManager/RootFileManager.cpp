#include "RootFileManager.h"

bool RootFileManager::Initialise(std::string configfile, DataModel &data)
{

  if (configfile != "")
    m_variables.Initialise(configfile);
  else
  {
    exit(1);
  }
  m_variables.Print();
  std::string outpath; 
  m_variables.Get("outpath",outpath);

  foutput = new TFile(outpath.c_str(),"RECREATE");

  return true;
}

bool RootFileManager::Execute()
{

  TH1D* htest = new TH1D("htest","htest",100,0,0);
  htest->FillRandom("gaus",1000);
  foutput->cd();
  htest->Write();

  m_data->Log->Log("test 2", 2, m_verbose);

  return true;
}

bool RootFileManager::Finalise()
{
  foutput->Close();
  return true;
}
