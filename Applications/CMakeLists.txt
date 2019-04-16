# CMakeLists.txt for src/exe
# Author: M. Guigue
# Created: Mar 6, 2019

# add_library(master_library_Rainette SHARED
#     dummy.cpp
# )

set( lib_dependencies 
    # ServiceDiscovery
    ToolChain_Rainette
    DummyTool_Rainette
    # master_library
    # Wrenches
    MyTool
    Logger_Rainette
    DummyTool_Rainette
    # ToolChainFactory
)

set( main_exe
    main
    # test
    # NodeDaemon
    # RemoteControl
)


pbuilder_executables( main_exe lib_dependencies )


# target_link_libraries(lib_dependencies Wrenches)


set( lib_dependencies 
    # ServiceDiscovery
    # ToolChain
    # DummyTool
    ToolChainFactory
    # Wrenches
)

set( test_exe
    # main
    test
    # NodeDaemon
    # RemoteControl
)
# pbuilder_executables( test_exe lib_dependencies)

