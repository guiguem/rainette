#include "TextWriter.h"

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

    m_file.open(m_filename.c_str());

    return true;
}

bool TextWriter::Execute()
{

    int a;
    double b;
    std::string c;

    Log("test logger", 1, m_verbose);
    m_data->Stores["DataName"]->Get("a", a);
    m_data->Stores["DataName"]->Get("b", b);
    m_data->Stores["DataName"]->Get("c", c);
    Log("test 2", 1, m_verbose);

    m_file << "Writing value to a file: " << a << "\n";

    return true;
}

bool TextWriter::Finalise()
{

    m_file.close();
    return true;
}
