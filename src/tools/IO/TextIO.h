#ifndef TextIO_H
#define TextIO_H

#include <iostream> // for string, ofstream
#include "IOBaseTool.h"   // for IOBaseTool
class DataModel;

class TextIO : public IOBaseTool
{
public:
    TextIO() : IOBaseTool() {}
    TextIO(std::string x) : IOBaseTool(x) {}

// public:
    // bool Initialise(std::string configfile, DataModel &data) override;
    // bool Execute() override; // = 0;
    // bool Finalise() override;

private:
    bool Read() override;
    bool Write() override;
    bool OpenFile() override;
    bool CloseFile() override;
    
    template <typename T>
    bool ReadFromFile();
    template <typename T>
    bool ReadVectorFromFile();
    template <typename T>
    bool SaveToFile();

    bool ReadVectorStringFromFile(); ///< A special function because reading std::string from a file is weird...
    bool SaveStringIntoFile(); ///< A special function because writing std::string from a file is weird...
    bool SaveVectorStringIntoFile(); ///< A special function because writing std::string from a file is weird...

private:
    std::ofstream m_outfile;
    std::ifstream m_infile;
};

REGISTER_FACTORY(Tool,TextIO)

template <typename T>
bool TextIO::SaveToFile()
{
    T object;
    if (!m_data->Stores[m_storename.c_str()]->Get(m_objectname, object))
    {
        std::cout << "Failed find" << m_objectname << std::endl;
        return false;
    };
    // Remove object
    T object_empty;
    m_data->Stores[m_storename.c_str()]->Set(m_objectname, object_empty);
    m_outfile << object;
    return true;
}

template <typename T>
bool TextIO::ReadFromFile()
{
    T object;
    m_infile >> object;
    std::cout << object << std::endl;
    m_data->Stores[m_storename.c_str()]->Set(m_objectname, object);
    return true;
}
template <typename T>
bool TextIO::ReadVectorFromFile()
{
    std::vector<T> v_object;
    T object;
    while (m_infile >> object){
      v_object.push_back(object);
    }
    m_data->Stores[m_storename.c_str()]->Set(m_objectname, v_object);
    m_infile.clear( );
    m_infile.seekg(0, std::ios::beg);
    return true;
}
#endif
