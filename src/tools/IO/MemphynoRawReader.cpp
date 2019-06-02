#include "MemphynoRawReader.h"
#include "HodoscopeIO.h"

bool MemphynoRawReader::Initialise(std::string configfile, DataModel &data)
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
    m_variables.Get("eventsperpacket", m_eventsPerPacket);

    Log("Here");
    m_hodoscopeIO = new CosmicCrisp::HodoscopeIO();

    // std::ostringstream oss;
    // oss << foldername << "/" << date << "T" << hour << "-port" << port << ".dat";
    Log(m_filename);
    // std::ifstream m_infile(m_filename.c_str(), std::ios::binary);
    m_infile.open(m_filename.c_str(), std::ios::binary);
    if (!m_infile.is_open())
    {
        Log("No such file or directory...");
        return false;
    }
    m_data->Stores[m_storename.c_str()] = new BoostStore(false, 2);
    return true;
}
bool MemphynoRawReader::Execute()
{
    Log("Exec");
    unsigned int byteCountTot = 0;
    unsigned int byteCount = 0;
    while (!m_infile.eof())
    {
        char currentChar = m_infile.get();
        // LDEBUG_ONCE(currentChar);
        std::string binaryC = m_hodoscopeIO->ConvertCharToBin(currentChar);
        if (binaryC.length() != 8)
        {
            Log("Problem in the file reading at byte ");
            return false;
        }

        ++byteCountTot;
        m_fullLine += binaryC;
        if (m_fullLine.length() % 8)
        {
            Log("problem in the char 2 bin conversion!");
            return false;
        }
        if (m_fullLine.length() == 64 * unsigned(m_eventsPerPacket))
        {
            std::cout << m_fullLine << std::endl;
            break;
        }
        else if (byteCount == (8 * m_eventsPerPacket - 1))
        {
            // Log(str("error: ") + byteCountTot << ' ' << fullLine.length() << ' ' << fullLine);
            Log("error");
        }
        else
        {
            ++byteCount;
        }
    }
    m_data->Stores[m_storename.c_str()]->Set(m_objectname, m_fullLine);
    m_fullLine = "";
    m_fullLine.clear();
    return true;
}
bool MemphynoRawReader::Finalise()
{
    m_infile.close();
    return true;
}

// return tru;
// e:;awReader::Finalise() {
//         return true;
//     };