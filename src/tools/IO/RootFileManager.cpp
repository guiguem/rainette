#include "RootFileManager.h"

bool RootFileManager::Initialise(std::string configfile, DataModel &data)
{

  if (configfile != "")
    m_variables.Initialise(configfile);
  else
  {
    exit(1);
  }
  m_data = &data;

  //m_variables.Print();
  std::string outpath; 
  m_variables.Get("outpath",outpath);

  foutput = new TFile(outpath.c_str(),"RECREATE");

  TTree * tree=new TTree("RawData","RawData");

//   tree->Branch("evt",&m_data->evt,"evt/L");
//   tree->Branch("scintID",&localcard.scintID,"scintID/I");
//   tree->Branch("Time",&localcard.Time);

//   m_data->AddTTree("RawData",tree);

  return true;
}

bool RootFileManager::Execute()
{

//  m_data->evt+=1;

//   for(int card=0;card<m_data->Cards.size();card++){
    
//     localcard.scintID=m_data->Cards.at(card)->scintID;
    
//     localcard.Time.clear();
//     localcard.Time=m_data->Cards.at(card)->Time;

//     delete m_data->Cards.at(card);
//     m_data->Cards.at(card)=0;

//     m_data->GetTTree("RawData")->Fill();    
//   }

//   m_data->Cards.clear();

  return true;
}

bool RootFileManager::Finalise()
{

//   m_data->GetTTree("RawData")->Write();
  
  foutput->Close();
  
//   m_data->DeleteTTree("RawData");
    
  delete foutput;
  foutput=0;
  
  return true;

}
