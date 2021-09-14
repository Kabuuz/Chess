set(INCLUDE_DIR_UT ${CMAKE_CURRENT_SOURCE_DIR}/mocks)

add_subdirectory(tests)

add_executable(${BINARY} main.cpp)

target_link_libraries(${BINARY} PUBLIC mainlib)
target_link_libraries(${BINARY} PUBLIC gtest gtest_main)
target_link_libraries(${BINARY} PUBLIC gmock gmock_main)
target_link_libraries(${BINARY} PUBLIC mainlib_ut)
