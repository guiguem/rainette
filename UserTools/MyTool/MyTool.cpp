#include "MyTool.h"

void MyTool::makeNoise() { std::cerr << "MyTool: " << m_x << "\n"; }

bool MyTool::Initialise(std::string configfile, DataModel &data)
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

    ////// Save some data to inter Tool/module persistant store (not mandatory)
    std::string configvalue = "important info";
    int a = 5;
    double b = 5.4;
    m_data->CStore.Set("name", configvalue);
    m_data->CStore.Set("a", a);
    m_data->CStore.Set("b", b);

    /////Set up a new store with multiple entries (mandatory)
    m_data->Stores["DataName"] = new BoostStore(false, 2);

    // set multi entry header info (not mandatory)
    std::string headervalue = "info";
    m_data->Stores["DataName"]->Header->Set("name", headervalue);
    m_data->Stores["DataName"]->Header->Set("a", a);
    m_data->Stores["DataName"]->Header->Set("b", b);

    return true;
}

bool MyTool::Execute()
{

    m_data->Log->Log("test 2", 2, m_verbose);
    int a = rand() % 10 + 1;
    double b = (rand() % 1000 + 1) / 10.0;
    std::string c = "stuff";

    m_data->Stores["DataName"]->Set("a", a);
    m_data->Stores["DataName"]->Set("b", b);
    m_data->Stores["DataName"]->Set("c", c);

    return true;
}

bool MyTool::Finalise()
{

    return true;
}
