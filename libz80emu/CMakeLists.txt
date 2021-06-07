include_directories(../include)

file (GLOB_RECURSE libfiles "./*cpp")

add_library(libz80emu STATIC ${libfiles})
target_link_libraries(libz80emu log)