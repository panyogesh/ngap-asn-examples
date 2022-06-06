cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

project(MagmaMainAsn)
file(GLOB magma_main_asn_SRC
     "*.h"
     "*.c"
     "*.cpp"
)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(magma_main_asn ${magma_main_asn_SRC})
