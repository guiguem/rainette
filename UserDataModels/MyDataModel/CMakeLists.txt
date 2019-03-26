# CMakeLists for MyDataModel
# Author: M. Guigue
# Date: Jan 15, 2019


set( MYDM_DICT_HEADERFILES
    MyDataModel.h
)

set( MYDM_HEADERFILES
    ${MYDM_DICT_HEADERFILES}
)

set( MYDM_SOURCEFILES
    MyDataModel.cpp
)


set (MYDM_DEP_LIBRARIES
 Store_Rainette
 BaseDataModel_Rainette
#  cppzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( MyDataModel MYDM_SOURCEFILES MYDM_DEP_LIBRARIES )
pbuilder_install_headers( ${MYDM_HEADERFILES} )

