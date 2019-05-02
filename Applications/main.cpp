#include <string>
#include "ToolChain.h"
#include "DummyTool.h"
#include "RootFileManager.h"
#include <iostream>

int main(int argc, char* argv[]){

  std::string conffile;
  if (argc==1)conffile="configfiles/Dummy/ToolChainConfig";
  else conffile=argv[1];

    ToolChain tools(conffile);

    std::cout << "Done here" << std::endl;
  
}

// #include <iostream>
// #include <string>

// #include "ToolBox.h"

// int main()
// {
//     std::cout << "main" << std::endl;
//     ToolBox toolchain;
//     auto wrench = toolchain.CreateTool("Wrench", "splash");
//     auto wrench2 = toolchain.CreateTool("MyTool", "splash");
//     // auto wrench2 = toolchain.CreateTool("Wrench", "bing");
//     // auto screwDriver = toolchain.CreateTool("ScrewDriver", "paff");
//     // wrench->makeNoise();
//     // wrench2->makeNoise();
//     // screwDriver->makeNoise();
//     return 0;
// }
