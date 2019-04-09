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
# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})


##################################################

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( RootFileManager RootFileManager_SOURCEFILES RootFileManager_DEP_LIBRARIES )
pbuilder_install_headers( ${RootFileManager_HEADERFILES} )


