/* This is the Rainette main executable.
It is suposed to over-seed the ToolDAQFramework one.
NOTE: WE COULD ALSO USE THE FRAMEWORK ONE IN CMAKELISTS
*/

#include <string>
#include "ToolChain.h"
#include "Factory.h"
#include <iostream>

int main(int argc, char *argv[])
{
	Factory<Tool>::showClasses("Tool");

    std::string conffile;
    if (argc == 1)
        conffile = "configfiles/Dummy/ToolChainConfig";
    else
        conffile = argv[1];

    ToolChain tools(conffile);

    std::cout << "Done here" << std::endl;
}
