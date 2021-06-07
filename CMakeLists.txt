cmake_minimum_required (VERSION 3.5)
project (Z80Emu)

include_directories(include libz80emu/Log/include)

add_subdirectory(libz80emu)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -static")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB_RECURSE sourcefiles "${source_dir}/*.cpp")

add_executable (Z80Emu ${sourcefiles})
target_link_libraries(Z80Emu libz80emu)
add_dependencies(Z80Emu libz80emu)