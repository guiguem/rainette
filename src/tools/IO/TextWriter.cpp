#include "TextWriter.h"

// Add the header to your object below
#include "TestObj.h"

/** @brief Method that transforms a const char into int (useful for switch logic) */
constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

// template <typename T> using VECTOR = std::vector<T>;

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
    m_variables.Get("objecttype", m_objecttype);

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
    if (m_objecttype == "")
    {
        std::cout << "Error: No object type given for TextWriter" << std::endl;
        return false;
    }

    m_file.open(m_filename.c_str());

    return true;
}

bool TextWriter::Execute()
{
    switch (str2int(m_objecttype.c_str()))
    {
        // Add your object below
    case (str2int("TestObj")):
    {
        return SaveToFile<TestObj>();
        break;
    }
    case (str2int("vector<TestObj>")):
    {
        return SaveToFile<std::vector<TestObj>>();
        break;
    }

    default:
        break;
    }

    return false;
}

bool TextWriter::Finalise()
{

    m_file.close();
    return true;
}
