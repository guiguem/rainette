# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( RootFileManager_DICT_HEADERFILES
    RootFileManager.h
)

set( RootFileManager_HEADERFILES
    ${RootFileManager_DICT_HEADERFILES}
)

set( RootFileManager_SOURCEFILES
    RootFileManager.cpp
)


set (RootFileManager_DEP_LIBRARIES
 BaseDataModel_Rainette
 Store_Rainette
 cppzmq
)


##################################  ROOT  ######################################
if ( NOT DEFINED ENV{ROOTSYS} )
  cmessage(FATAL_ERROR "$ROOTSYS is not defined, please set up root first.")
else()
  cmessage(STATUS "Using ROOT installed at $ENV{ROOTSYS}")
  set(CMAKE_ROOTSYS $ENV{ROOTSYS})
endif()

##################################################

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( RootFileManager RootFileManager_SOURCEFILES RootFileManager_DEP_LIBRARIES )
pbuilder_install_headers( ${RootFileManager_HEADERFILES} )


