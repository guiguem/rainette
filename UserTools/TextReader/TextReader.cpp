#include "TextReader.h"

bool TextReader::Initialise(std::string configfile, DataModel &data)
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

bool TextReader::Execute()
{

    m_data->Log->Log("test 2", 2, m_verbose);

    m_file << "Writing this to a file.\n";

    return true;
}

bool TextReader::Finalise()
{

    m_file.close();
    return true;
}
