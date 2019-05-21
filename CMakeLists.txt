cmake_minimum_required(VERSION 3.1)

cmake_policy( SET CMP0048 NEW ) # version in project()
project( Rainette VERSION 1.1.6 )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/ToolDAQFramework/src/vendor/scarab/cmake )
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/ToolDAQFramework/src/vendor/cppzmq/cmake )
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

include( PackageBuilder )

pbuilder_prepare_project()

#############
# Submodules
#############

pbuilder_add_submodule( ToolDAQFramework ToolDAQFramework )
set( CosmicCrisp_ENABLE_EXECUTABLES OFF )
pbuilder_add_submodule( CosmicCrisp CosmicCrisp )

set( Scarab_BUILD_CODEC_JSON OFF CACHE BOOL "No coded" FORCE)
set( Scarab_BUILD_CODEC_YAML OFF CACHE BOOL "No codec" FORCE)
set( Scarab_BUILD_AUTHENTICATION OFF CACHE BOOL "No auth" FORCE)
set( Scarab_BUILD_PARAM OFF CACHE BOOL "No param" FORCE)

# require C++14
set_option( USE_CPP11 FALSE )
set_option( USE_CPP14 TRUE )
set(CMAKE_CXX_STANDARD 14)

#############
# Rainette
#############

# subdirectories
include_directories (BEFORE
    # ${PROJECT_SOURCE_DIR}/UserTools/CosmicCrispConverter
    ${PROJECT_SOURCE_DIR}/src/tools/Tests
    ${PROJECT_SOURCE_DIR}/src/tools/IO
    ${PROJECT_SOURCE_DIR}/src/exe
)

# add_subdirectory (RainetteDataModels)
# add_subdirectory (UserTools/CosmicCrispConverter)
add_subdirectory (src/tools/Tests)
add_subdirectory (src/tools/IO)
add_subdirectory (src/exe)

pbuilder_variables_for_parent()