cmake_minimum_required(VERSION 3.15)

add_library(list)
add_library(ds::list ALIAS list)

target_sources(list PRIVATE
    src/list.c
)
target_include_directories(list PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
