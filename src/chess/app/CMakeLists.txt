set(LIB_NAME chess_app_lib)

add_library(${LIB_NAME} OBJECT)

target_sources(${LIB_NAME}
    PUBLIC
    ${INCLUDE_DIR}/mygame/chess/app/ChessApplication.hpp

    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ChessApplication.cpp
    )

target_include_directories(${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
    )

target_link_libraries(${LIB_NAME} PUBLIC sfml-graphics)

target_compile_options(${LIB_NAME} PUBLIC -Werror -Wall -Wextra)