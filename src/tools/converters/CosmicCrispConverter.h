#ifndef CosmicCrispConverter_H
#define CosmicCrispConverter_H

#include <string>
#include <iostream>

#include "Factory.h" // for Factory
#include "Tool.h"

#include "HodoscopeData.h"
// #include "RainetteDataModel.h"
class RainetteDataModel;

class CosmicCrispConverter : public Tool
{
  public:
    CosmicCrispConverter(std::string x) : m_x(x) {}
    CosmicCrispConverter() {}

  public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

  private:
    int m_verbose;
    std::string m_x;

};

REGISTER_FACTORY(Tool,CosmicCrispConverter)


#endif
