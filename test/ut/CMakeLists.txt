set(INCLUDE_DIR_UT 
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs
)

add_executable(${BINARY} main.cpp)

target_include_directories(${BINARY} PUBLIC 
${INCLUDE_DIR_UT}

${GTEST_INCLUDE}
${GMOCK_INCLUDE}
)

target_link_libraries(${BINARY} PUBLIC mainlib)
target_link_libraries(${BINARY} PUBLIC gtest gtest_main)
target_link_libraries(${BINARY} PUBLIC gmock gmock_main)

add_subdirectory(tests)