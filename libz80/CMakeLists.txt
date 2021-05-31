
include_directories(${PROJECT_SOURCE_DIR}/include)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -static")

file (GLOB_RECURSE libfiles "./*cpp")

add_library(libz80 STATIC ${libfiles})