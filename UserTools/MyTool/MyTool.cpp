#include "MyTool.h"

bool MyTool::Initialise(std::string configfile, MyDataModel &data)
{

    if (configfile != "")
        m_variables.Initialise(configfile);
    else {
        exit(1);
    }
    //m_variables.Print();

    m_data = &data;
    m_variables.Get("verbose", m_verbose);

    return true;
}

bool MyTool::Execute()
{

    m_data->Log->Log("test 2", 2, m_verbose);

    return true;
}

bool MyTool::Finalise()
{

    return true;
}
