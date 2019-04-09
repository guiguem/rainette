#include "RootFileCreator.h"

bool RootFileCreator::Initialise(std::string configfile, DataModel &data)
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

bool RootFileCreator::Execute()
{

    m_data->Log->Log("test 2", 2, m_verbose);

    return true;
}

bool RootFileCreator::Finalise()
{

    return true;
}
