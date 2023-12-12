cmake_minimum_required(VERSION 3.10)
project(bfpp)
set(CMAKE_CXX_STANDARD 17)

# Adding sources
set(SOURCES
    sources/main.cpp
    sources/getArguments.cpp
    sources/bfppFunction.cpp
    sources/bfToCpp.cpp
)

# Binary
add_executable(bfpp ${SOURCES})
set_property(TARGET bfpp PROPERTY CXX_STANDARD 17)
target_compile_features(bfpp PRIVATE cxx_std_17)