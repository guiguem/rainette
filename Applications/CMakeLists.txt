# CMakeLists.txt for src/exe
# Author: M. Guigue
# Created: Mar 6, 2019

# add_library(master_library_Rainette SHARED
#     dummy.cpp
# )

set( lib_dependencies 
    ToolChain_Rainette
    DummyTool_Rainette
    Logger_Rainette
    DummyTool_Rainette
    Wrenches
    MyTool
    TextReader
)

set( main_exe
    main
)


pbuilder_executables( main_exe lib_dependencies )


