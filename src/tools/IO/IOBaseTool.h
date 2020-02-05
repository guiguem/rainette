#ifndef IOBaseTool_H
#define IOBaseTool_H

#include <iostream>  // for string, ofstream
#include "Factory.h" // for Factory
#include "Tool.h"    // for Tool
class DataModel;

enum IOMode
{
    Read = 0,
    Write
};

class IOBaseTool : public Tool
{
public:
    IOBaseTool() {}
    IOBaseTool(std::string x) : m_x(x) {}

public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override; // = 0;
    bool Finalise() override;

private:
    virtual bool OpenFile() { return false; };  ///< Open file depending on the mode; Implemented in derived class
    virtual bool CloseFile() { return false; }; ///< Close file; Implemented in derived class)
    virtual bool Read();                        ///< Run during Execute() depending on IOMode; Implemented in derived class
    virtual bool Write();                       ///< Run during Execute() depending on IOMode; Implemented in derived class

protected:
    int m_verbose;
    std::string m_x;
    std::string m_filename;
    std::string m_objectname;
    std::string m_objecttype;
    std::string m_storename;
    IOMode m_mode;
};

REGISTER_FACTORY(Tool, IOBaseTool)

#endif
