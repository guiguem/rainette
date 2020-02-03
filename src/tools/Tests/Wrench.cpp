#include "Wrench.h"

void Wrench::makeNoise() { std::cerr << "Wrench: " << m_x << "\n"; }

bool Wrench::Initialise(std::string configfile, DataModel &data)
{

    if (configfile != "")
        m_variables.Initialise(configfile);

    //   m_data= &data;

    m_variables.Get("verbose", m_verbose);

    //   Log("test 1",1,m_verbose);

    return true;
}

bool Wrench::Execute()
{

    //   Log(makeNoise(),2,m_verbose);
    Log(std::string("Hey listen to my noise: ") + m_x, 1, m_verbose);
    sleep(2);
    return true;
}

bool Wrench::Finalise()
{

    return true;
}
