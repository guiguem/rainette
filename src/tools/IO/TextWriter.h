#ifndef MYTOOL_H
#define MYTOOL_H

#include <iostream> // for string, ofstream
#include "Tool.h"   // for Tool
class DataModel;

class TextWriter : public Tool::Registrar<TextWriter>
{
public:
    TextWriter(std::string x) : m_x(x) {}

public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override; // = 0;
    bool Finalise() override;

private:
    template <typename T>
    bool SaveToFile();

    // virtual bool ExtractSaveObjects();

private:
    int m_verbose;
    std::string m_x;
    std::string m_filename;
    std::string m_objectname;
    std::string m_objecttype;
    std::string m_storename;
    std::ofstream m_file;
};

template <typename T>
bool TextWriter::SaveToFile()
{
    T object;
    if (!m_data->Stores[m_storename.c_str()]->Get(m_objectname, object))
    {
        std::cout << "Failed " << m_objectname << std::endl;
    };
    m_file <<  object;
    return true;
}
#endif
