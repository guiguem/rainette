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
    RootFileManager
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
    RootFileManager
    # Wrenches
)

set( test_exe
    # main
    test
    # NodeDaemon
    # RemoteControl
)
# pbuilder_executables( test_exe lib_dependencies)

##################################  ROOT  ######################################
find_package (ROOT)
if (ROOT_FOUND)
    pbuilder_add_ext_libraries (${ROOT_LIBRARIES})
    message(STATUS "ROOT found!")
else (ROOT_FOUND)
    message(FATAL "Unable to find ROOT")
endif (ROOT_FOUND)
include_directories (${ROOT_INCLUDE_DIR})


##################################################

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )
