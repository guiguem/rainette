#include "CosmicCrispConverter.h"

void CosmicCrispConverter::makeNoise() { std::cerr << "CosmicCrispConverter: " << m_x << "\n"; }

bool CosmicCrispConverter::Initialise(std::string configfile, DataModel &data)
{

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

bool CosmicCrispConverter::Execute()
{

    m_data->Log->Log("test 2", 2, m_verbose);

    return true;
}

bool CosmicCrispConverter::Finalise()
{

    return true;
}
