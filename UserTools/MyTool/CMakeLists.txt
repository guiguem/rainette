# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( MyTool_DICT_HEADERFILES
    MyTool.h
)

set( MyTool_HEADERFILES
    ${MyTool_DICT_HEADERFILES}
)

set( MyTool_SOURCEFILES
    MyTool.cpp
)


set (MyTool_DEP_LIBRARIES
 BaseDataModel
 Store_Rainette
 cppzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( MyTool MyTool_SOURCEFILES MyTool_DEP_LIBRARIES )
pbuilder_install_headers( ${MyTool_HEADERFILES} )

