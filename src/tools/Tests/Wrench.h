#include "Tool.h"

class Wrench : public Tool
{
  public:
    Wrench() {}
    Wrench(std::string x) : m_x(x) {}

    void makeNoise(); // { std::cerr << "Cat: " << m_x << "\n"; }

    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

  private:
    std::string m_x;
    int m_verbose;
};

REGISTER_FACTORY(Tool,Wrench)  