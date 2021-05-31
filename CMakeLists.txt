cmake_minimum_required (VERSION 3.5)
project (Z80Emu)

add_subdirectory(libz80)

include_directories(${PROJECT_SOURCE_DIR}/include)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -static")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB_RECURSE sourcefiles "${source_dir}/*.cpp")

add_executable (Z80Emu ${sourcefiles})
target_link_libraries(Z80Emu libz80)
add_dependencies(Z80Emu libz80)