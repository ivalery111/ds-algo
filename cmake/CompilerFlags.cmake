option(WARNINGS_AS_ERROR "Compiler warnings as error" ON)
if(WARNINGS_AS_ERROR)
    set(COMPILER_FLAGS ${COMPILER_FLAGS} "-Werror")
endif()

set(CLANG_WARNINGS
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Wunused"
    "-Wconversion"
    "-Wcast-align"
    "-Wshadow"
    "-Wsign-conversion"
    "-Wshadow"
)

set(GCC_WARNINGS ${CLANG_WARNINGS}
    "-Wmisleading-indentation"
    "-Wduplicated-cond"
    "-Wduplicated-branches"
    "-Wlogical-op"
)

if(CMAKE_C_COMPILER_ID MATCHES GNU)
    set(COMPILER_FLAGS ${COMPILER_FLAGS} ${GCC_WARNINGS})  
elseif(CMAKE_C_COMPILER_ID MATCHES CLANG)
    set(COMPILER_FLAGS ${COMPILER_FLAGS} ${CLANG_WARNINGS})
endif()
