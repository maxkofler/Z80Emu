cmake_minimum_required (VERSION 3.5)
project (Z80Emu)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB_RECURSE source_files "${source_dir}/*.cpp")

add_executable (Z80Emu.out ${source_files})
