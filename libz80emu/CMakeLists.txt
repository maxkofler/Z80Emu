include_directories(../include Log/include)

add_subdirectory(Log)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -static")

file (GLOB_RECURSE libfiles "./*cpp")

add_library(libz80emu STATIC ${libfiles})
target_link_libraries(libz80emu log)