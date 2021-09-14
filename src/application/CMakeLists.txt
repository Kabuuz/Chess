set(LIB_NAME application_lib)

add_library(${LIB_NAME} OBJECT)

target_sources(${LIB_NAME}
    PUBLIC
    ${INCLUDE_DIR}/mygame/application/Application.hpp
    ${INCLUDE_DIR}/mygame/application/IApplication.hpp

    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Application.cpp
    )

target_include_directories(${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
    )

target_link_libraries(${LIB_NAME} PUBLIC sfml-graphics)

target_compile_options(${LIB_NAME} PUBLIC -Werror -Wall -Wextra)
