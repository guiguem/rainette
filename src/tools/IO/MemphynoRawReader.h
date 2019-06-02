#ifndef MemphynoRawReader_H
#define MemphynoRawReader_H

#include <iostream> // for string, ofstream
#include "Tool.h"   // for Tool
class DataModel;
namespace CosmicCrisp{
    class HodoscopeIO;
};

class MemphynoRawReader : public Tool::Registrar<MemphynoRawReader>
{
public:
    MemphynoRawReader(std::string x) : m_x(x) {}

public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

private:
    CosmicCrisp::HodoscopeIO* m_hodoscopeIO;
    int m_verbose;
    std::string m_filename;
    std::string m_storename;
    std::string m_objectname;
    std::ifstream m_infile;
    std::string m_fullLine;
    int m_eventsPerPacket;
    std::string m_x;

};
#endif