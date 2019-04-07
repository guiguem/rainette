# CMakeLists for  ToolChain
# Author: M. Guigue
# Date: Jan 15, 2019

set (WRENCHES_HEADERS
    Wrench.h
)
set (WRENCHES_SOURCES
    Wrench.cpp
)
set (WRENCHES_DEP_LIBRARIES
    Store_Rainette
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

# pbuilder_library( ToolChain TOOLCHAIN_SOURCEFILES TOOLCHAIN_DEP_LIBRARIES )
# pbuilder_install_headers( ${TOOLCHAIN_HEADERFILES} )
pbuilder_library( Wrenches WRENCHES_SOURCES WRENCHES_DEP_LIBRARIES )
pbuilder_install_headers( ${WRENCHES_HEADERS} )
