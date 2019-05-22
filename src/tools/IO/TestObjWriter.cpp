#include "TestObjWriter.h"

bool TestObjWriter::Execute()
{

    TestObj object(m_objectname);


    if (!m_data->Stores[m_storename.c_str()]->Get(m_objectname, object2))
    {
            std::cout << "Failed " << m_objectname << std::endl;
    };


    return true;
}