# CMakeLists.txt for src/exe
# Author: C. Riccio
# Created: May 3, 2019

set( lib_dependencies 
    ToolChain_Rainette
    DummyTool_Rainette
    Logger_Rainette
    MyTool
    TextReader
    RootFileManager
)

set( main_exe
    main
)

pbuilder_executables( main_exe lib_dependencies )
