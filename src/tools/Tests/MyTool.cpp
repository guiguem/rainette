#include "MyTool.h"

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

    ////// Save some data to inter Tool/module persistant store
    std::string configvalue = "important info";
    int a = 5;
    double b = 5.4;
    // TestObj testobj;
    // m_data->CStore.Set("name", configvalue);
    // m_data->CStore.Set("a", a);
    // m_data->CStore.Set("b", b);
    // m_data->CStore.Set("TestObj", testobj);

    /////Set up a new store with multiple entries
    m_data->Stores["DataName"] = new BoostStore(false, 2);

    // set multi entry header info
    // std::string headervalue = "info";
    // m_data->Stores["DataName"]->Header->Set("name", headervalue);
    // m_data->Stores["DataName"]->Header->Set("a", a);
    // m_data->Stores["DataName"]->Header->Set("b", b);
    // m_data->Stores["DataName"]->Header->Set("TestObj", testobj);

    return true;
}

bool MyTool::Execute()
{

    m_data->Log->Log("test 2", 2, m_verbose);

    //// Generate random data
    int a = rand() % 10 + 1;
    double b = (rand() % 1000 + 1) / 10.0;
    std::string c = "stuff";
    std::cout << a << std::endl;
    
    TestObj testobj(std::string("DataName"));
    testobj.SetA(1.3);
    testobj.SetB(32.2);

    m_data->Stores["DataName"]->Set("a", a);
    m_data->Stores["DataName"]->Set("b", b);
    m_data->Stores["DataName"]->Set("TestObj", testobj);
    m_data->Stores["DataName"]->Print();
    // m_data->Stores["DataName"]->Save("mytest.txt");

    // double a2;
    // m_data->Stores["DataName"]->Get("a2", a2);
    // std::cout << a2 << std::endl;

    return true;
}

bool MyTool::Finalise()
{

    return true;
}
