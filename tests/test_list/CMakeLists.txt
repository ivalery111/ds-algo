add_executable(test_list test_list.c)

target_include_directories(test_list
    PRIVATE ${CMAKE_SOURCE_DIR}/src/list/include
)
target_link_libraries(test_list ds::list -fsanitize=address)
target_compile_options(test_list PRIVATE ${COMPILER_FLAGS})

add_test(
    NAME test_list
    COMMAND test_list
)