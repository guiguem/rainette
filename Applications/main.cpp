/* This is the Rainette main executable.
It is suposed to over-seed the ToolDAQFramework one.
*/

#include <string>
#include "ToolChain.h"
#include "DummyTool.h"
#include <iostream>

int main(int argc, char *argv[])
{

    std::cout << "Main here" << std::endl;
    std::string conffile;
    if (argc == 1)
        conffile = "configfiles/Dummy/ToolChainConfig";
    else
        conffile = argv[1];

    ToolChain tools(conffile);

    std::cout << "Done here" << std::endl;
}
