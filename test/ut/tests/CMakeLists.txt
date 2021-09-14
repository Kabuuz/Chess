add_subdirectory(temp)

add_library(mainlib_ut STATIC)

target_link_libraries(mainlib_ut PUBLIC temp_ut)