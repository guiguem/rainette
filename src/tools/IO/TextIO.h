#ifndef TextIO_H
#define TextIO_H

#include <iostream> // for string, ofstream
#include "Tool.h"   // for Tool
class DataModel;

enum IOMode
{
    Read = 0,
    Write
};

class TextIO : public Tool::Registrar<TextIO>
{
public:
    TextIO(std::string x) : m_x(x) {}

public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override; // = 0;
    bool Finalise() override;

private:
    bool Read();
    bool Write();
    template <typename T>
    bool ReadFromFile();
    template <typename T>
    bool ReadVectorFromFile();

    bool ReadVectorStringFromFile(); ///< A special function because reading std::string from a file is weird...
    bool SaveStringIntoFile(); ///< A special function because writing std::string from a file is weird...
    bool SaveVectorStringIntoFile(); ///< A special function because writing std::string from a file is weird...
    template <typename T>
    bool SaveToFile();

private:
    int m_verbose;
    std::string m_x;
    std::string m_filename;
    std::string m_objectname;
    std::string m_objecttype;
    std::string m_storename;
    std::ofstream m_outfile;
    std::ifstream m_infile;
    IOMode m_mode;
};

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
    return true;
}
#endif
