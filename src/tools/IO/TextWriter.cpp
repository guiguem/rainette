#include "TextWriter.h"
#include "ToolBox.h"

bool TextWriter::Initialise(std::string configfile, DataModel &data)
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
    m_variables.Get("filename", m_filename);
    m_variables.Get("storename", m_storename);
    m_variables.Get("objectname", m_objectname);
    // m_variables.Get("objecttype", m_objecttype);

    if (m_filename == "")
    {
        std::cout << "Error: No output file name given for TextWriter" << std::endl;
        return false;
    }
    if (m_objectname == "")
    {
        std::cout << "Error: No object name given for TextWriter" << std::endl;
        return false;
    }
    if (m_storename == "")
    {
        std::cout << "Error: No object type given for TextWriter" << std::endl;
        return false;
    }

    m_file.open(m_filename.c_str());

    return true;
}

bool TextWriter::Execute()
{

    int a;
    double b;
    std::string c;
    TestObj object2(m_objectname);
    // auto object = m_objectbox.CreateSerialObject(m_objecttype, "mybject");

    // Log("test logger", 1, m_verbose);
    // m_data->Stores["DataName"]->Get("a", a);
    // m_data->Stores["DataName"]->Get("b", b);
    if (!m_data->Stores[m_storename.c_str()]->Get(m_objectname, object2))
    {
            std::cout << "Failed " << m_objectname << std::endl;
    };
    // Log(object->PrintAsString(), 1, m_verbose);

    m_file <<  object2 << "\n";

    return true;
}

bool TextWriter::Finalise()
{

    m_file.close();
    return true;
}
