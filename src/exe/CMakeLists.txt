# CMakeLists.txt for src/exe
# Author: C. Riccio
# Created: May 3, 2019

set( lib_dependencies 
    ToolChain_Rainette
    DummyTool_Rainette
    IOTools
    TestsTools
)

# we could also just point to the ToolDAQFramework one
set( main_exe
    main
)

pbuilder_executables( main_exe lib_dependencies )
