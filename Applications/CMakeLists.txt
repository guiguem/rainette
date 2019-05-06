# CMakeLists.txt for src/exe
# Author: C. Riccio
# Created: May 3, 2019


set( lib_dependencies 
    ToolChain_Rainette
    DummyTool_Rainette
    RootFileManager
    MyTool
    Logger_Rainette
    DummyTool_Rainette
)

set( main_exe
    main
)

pbuilder_executables( main_exe lib_dependencies )


# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )
