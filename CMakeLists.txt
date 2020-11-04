cmake_minimum_required(VERSION 3.15)

project(ds-algo C)

# TODO: standart project settings

set(C_STANDARD 11)

# TODO: add sanitizers

include(cmake/CompilerFlags.cmake)
include(cmake/EnableTests.cmake)
include(cmake/BuildType.cmake)

add_subdirectory(src)
