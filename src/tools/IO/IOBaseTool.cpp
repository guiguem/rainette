#include "IOBaseTool.h"

// Add the header to your object below
// #include "TestObj.h"

/** @brief Method that transforms a const char into int (useful for switch logic) */
constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

// template <typename T> using VECTOR = std::vector<T>;

bool IOBaseTool::Initialise(std::string configfile, DataModel &data)
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
        if (!OpenFile()){
            std::cerr << "Filed opening file: " << m_filename << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Reading data mode" << std::endl;
        m_mode = IOMode::Read;
        if (!OpenFile()){
          std::cerr << "Filed opening file: " << m_filename << std::endl;
          return false;
        }
        m_data->Stores[m_storename.c_str()] = new BoostStore(false, 2);
    }

    if (m_filename == "")
    {
        std::cout << "Error: No output file name given for IOBaseTool" << std::endl;
        return false;
    }
    if (m_objectname == "")
    {
        std::cout << "Error: No object name given for IOBaseTool" << std::endl;
        return false;
    }
    if (m_storename == "")
    {
        std::cout << "Error: No store name given for IOBaseTool" << std::endl;
        return false;
    }
    if (m_objecttype == "")
    {
        std::cout << "Error: No object type given for IOBaseTool" << std::endl;
        return false;
    }

    return true;
}

bool IOBaseTool::Execute()
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

bool IOBaseTool::Read()
{
    std::cout << "Reading" << std::endl;
    switch (str2int(m_objecttype.c_str()))
    {
    // Add your object below
    case (str2int("std::string")):
    {
        // Special treatment for std::string
        // return ReadFromFile<std::string>();
        break;
    }
    case (str2int("std::vector<std::string>")):
    {
        // return ReadVectorFromFile<std::string>();
        // return ReadVectorStringFromFile();
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

bool IOBaseTool::Write()
{
    std::cout << "Writing" << std::endl;
    switch (str2int(m_objecttype.c_str()))
    {
    // Add your object below
    case (str2int("std::string")):
    {
        // return SaveStringIntoFile();
        break;
    }
    case (str2int("std::vector<std::string>")):
    {
        // return SaveVectorStringIntoFile();
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

bool IOBaseTool::Finalise()
{

    CloseFile();
    return true;
}
