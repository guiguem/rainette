# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( Data_DICT_HEADERFILES
    EventTest.h
    TestObj.h
)

set( Data_HEADERFILES
    ${Data_DICT_HEADERFILES}
)

set( Data_SOURCEFILES
    EventTest.cpp
)


set (Data_DEP_LIBRARIES
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

# pbuilder_library( Data Data_SOURCEFILES Data_DEP_LIBRARIES )
# pbuilder_install_headers( ${Data_HEADERFILES} )

