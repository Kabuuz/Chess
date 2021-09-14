set(BINARY ${CMAKE_PROJECT_NAME}_UT)

set(GTEST_INCLUDE ${DEPENDENCY_DIR}/googletest/googletest/include)
set(GMOCK_INCLUDE ${DEPENDENCY_DIR}/googletest/googlemock/include)

add_subdirectory(ut)