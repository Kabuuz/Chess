set(LIB_NAME temp_ut)

add_library(${LIB_NAME} OBJECT)

target_sources(${LIB_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/DummyTest.cpp
    )

target_include_directories(${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
    ${INCLUDE_DIR_UT}
    ${GTEST_INCLUDE}
    ${GMOCK_INCLUDE}
    )
