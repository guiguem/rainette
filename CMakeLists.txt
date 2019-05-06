cmake_minimum_required(VERSION 3.1)

cmake_policy( SET CMP0048 NEW ) # version in project()
project( Rainette VERSION 1.1.6 )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/ToolDAQFramework/src/vendor/scarab/cmake )
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/ToolDAQFramework/src/vendor/cppzmq/cmake )
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

# list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/Cicada/Scarab/cmake )
include( PackageBuilder )

pbuilder_prepare_project()

pbuilder_add_submodule( ToolDAQFramework ToolDAQFramework )


MESSAGE (STATUS "HEREHEREH" ${EXTERNAL_LIBRARIES})

set( Scarab_BUILD_CODEC_JSON OFF CACHE BOOL "No coded" FORCE)
set( Scarab_BUILD_CODEC_YAML OFF CACHE BOOL "No codec" FORCE)
set( Scarab_BUILD_AUTHENTICATION OFF CACHE BOOL "No auth" FORCE)
set( Scarab_BUILD_PARAM OFF CACHE BOOL "No param" FORCE)


# require C++14
set_option( USE_CPP11 FALSE )
set_option( USE_CPP14 TRUE )
set(CMAKE_CXX_STANDARD 14)

##################################  ROOT  ######################################

find_package (ROOT)
if (ROOT_FOUND)
    pbuilder_add_ext_libraries (${ROOT_LIBRARIES})
    message(STATUS "ROOT found!")
else (ROOT_FOUND)
    message(FATAL "Unable to find ROOT")
endif (ROOT_FOUND)
include_directories (${ROOT_INCLUDE_DIR})


##################### ROOT END #############################

#############
# ToolDAQ
#############

# subdirectories
include_directories (BEFORE
    # ${PROJECT_SOURCE_DIR}/UserDataModels/MyDataModel
    ${PROJECT_SOURCE_DIR}/UserTools/MyTool
    ${PROJECT_SOURCE_DIR}/UserTools/Wrench
    ${PROJECT_SOURCE_DIR}/UserTools/RootFileManager
    ${PROJECT_SOURCE_DIR}/Applications
)

# add_subdirectory (UserDataModels/MyDataModel)
add_subdirectory (UserTools/MyTool)
add_subdirectory (UserTools/Wrench)
add_subdirectory (UserTools/RootFileManager)
add_subdirectory (Applications)

pbuilder_variables_for_parent()