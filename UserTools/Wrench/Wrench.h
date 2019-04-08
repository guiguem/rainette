#include "Tool.h"

class Wrench : public Tool::Registrar<Wrench>
{
  public:
    Wrench(std::string x) : m_x(x) {}

    void makeNoise(); // { std::cerr << "Cat: " << m_x << "\n"; }

    bool Initialise(std::string configfile, DataModel &data);
    bool Execute();
    bool Finalise();

  private:
    std::string m_x;
};