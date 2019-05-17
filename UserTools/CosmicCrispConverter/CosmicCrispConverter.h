#ifndef CosmicCrispConverter_H
#define CosmicCrispConverter_H

#include <string>
#include <iostream>

#include "Tool.h"

#include "HodoscopeData.h"
// #include "RainetteDataModel.h"
class RainetteDataModel;

class CosmicCrispConverter : public Tool::Registrar<CosmicCrispConverter>
{
  public:
    CosmicCrispConverter(std::string x) : m_x(x) {}

    void makeNoise(); // { std::cerr << "Cat: " << m_x << "\n"; }

  public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

  private:
    int m_verbose;
    std::string m_x;

};

#endif
