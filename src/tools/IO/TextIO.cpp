#include "TextIO.h"

// Add the header to your object below
#include "TestObj.h"

/** @brief Method that transforms a const char into int (useful for switch logic) */
constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

// template <typename T> using VECTOR = std::vector<T>;

bool TextIO::Initialise(std::string configfile, DataModel &data)
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
    std::string mode;
    m_variables.Get("mode", mode);
    if (std::strcmp(mode.c_str(), "write") == 0)
    {
        std::cout << "Writing data mode" << std::endl;
        m_mode = IOMode::Write;
        m_outfile.open(m_filename.c_str());
    }
    else
    {
        std::cout << "Reading data mode" << std::endl;
        m_mode = IOMode::Read;
        m_infile.open(m_filename.c_str(), std::ios::in);
        m_data->Stores[m_storename.c_str()] = new BoostStore(false, 2);
    }

    if (m_filename == "")
    {
        std::cout << "Error: No output file name given for TextIO" << std::endl;
        return false;
    }
    if (m_objectname == "")
    {
        std::cout << "Error: No object name given for TextIO" << std::endl;
        return false;
    }
    if (m_storename == "")
    {
        std::cout << "Error: No store name given for TextIO" << std::endl;
        return false;
    }
    if (m_objecttype == "")
    {
        std::cout << "Error: No object type given for TextIO" << std::endl;
        return false;
    }

    return true;
}

bool TextIO::Execute()
{
    if (m_mode == IOMode::Read)
    {
        return Read();
    }
    else if (m_mode == IOMode::Write)
    {
        return Write();
    }
    return true;
}

bool TextIO::Read()
{
    std::cout << "Reading" << std::endl;
    if (m_infile.eof())
    {
        std::cout << "End of file reached" << std::endl;
        return true;
    }
    switch (str2int(m_objecttype.c_str()))
    {
    // Add your object below
    case (str2int("std::string")):
    {
        // Special treatment for std::string
        return ReadFromFile<std::string>();
        break;
    }
    case (str2int("std::vector<std::string>")):
    {
        // return ReadVectorFromFile<std::string>();
        return ReadVectorStringFromFile();
        break;
    }
    case (str2int("TestObj")):
    {
        return ReadFromFile<TestObj>();
        break;
    }
    case (str2int("vector<TestObj>")):
    {
        return ReadVectorFromFile<TestObj>();
        break;
    }
    default:
    {
        std::cerr << "Unknown object: " << m_objecttype << std::endl;
        return false;
    }
    }
    std::cout << "Done reading" << std::endl;
    return true;
}

bool TextIO::Write()
{
    std::cout << "Writing" << std::endl;
    switch (str2int(m_objecttype.c_str()))
    {
    // Add your object below
    case (str2int("std::string")):
    {
        return SaveStringIntoFile();
        break;
    }
    case (str2int("std::vector<std::string>")):
    {
        return SaveVectorStringIntoFile();
        break;
    }
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
    {
        std::cerr << "Unknown object: " << m_objecttype << std::endl;
        return false;
    }
    }

    return false;
}

bool TextIO::Finalise()
{

    m_infile.close();
    m_outfile.close();
    return true;
}

bool TextIO::ReadVectorStringFromFile()
{
    std::string value;
    std::vector<std::string> v_string;
    while (std::getline(m_infile, value, '\n')){
        v_string.push_back(value);
    };
    m_data->Stores[m_storename.c_str()]->Set(m_objectname, v_string);
    m_infile.clear();
    m_infile.seekg(0, std::ios::beg);
    return true;
}

bool TextIO::SaveStringIntoFile()
{
    std::string object;
    if (!m_data->Stores[m_storename.c_str()]->Get(m_objectname, object))
    {
        std::cout << "Failed getting" << m_objectname << " from store" << std::endl;
    };
    m_outfile << object << "\n";
    return true;
}
bool TextIO::SaveVectorStringIntoFile()
{
    std::vector<std::string> avector;
    if (!m_data->Stores[m_storename.c_str()]->Get(m_objectname, avector))
    {
        std::cout << "Failed getting <" << m_objectname << "> of type <" << m_objecttype << "> from store" << std::endl;
    };

    for (std::vector<std::string>::iterator iter = avector.begin(); iter != avector.end(); ++iter)
    {
        m_outfile << (*iter).c_str() << "\n";
    }
    return true;
}