# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( CosmicCrispConverter_DICT_HEADERFILES
    CosmicCrispConverter.h
)

set( CosmicCrispConverter_HEADERFILES
    ${CosmicCrispConverter_DICT_HEADERFILES}
)

set( CosmicCrispConverter_SOURCEFILES
    CosmicCrispConverter.cpp
)

set (CosmicCrispConverter_DEP_LIBRARIES
 BaseDataModel_Rainette
 Store_Rainette
 cppzmq
 Data_Rainette
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( CosmicCrispConverter CosmicCrispConverter_SOURCEFILES CosmicCrispConverter_DEP_LIBRARIES )
pbuilder_install_headers( ${CosmicCrispConverter_HEADERFILES} )

