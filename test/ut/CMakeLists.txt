set(INCLUDE_DIR_UT ${CMAKE_CURRENT_SOURCE_DIR}/mocks)



add_executable(${BINARY} main.cpp)

target_include_directories(${BINARY} PUBLIC 
${GTEST_INCLUDE}
${GMOCK_INCLUDE}
)

target_link_libraries(${BINARY} PUBLIC mainlib)
target_link_libraries(${BINARY} PUBLIC gtest gtest_main)
target_link_libraries(${BINARY} PUBLIC gmock gmock_main)

add_subdirectory(tests)