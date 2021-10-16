set(LIB_NAME chess_table_lib)

add_library(${LIB_NAME} OBJECT)

target_sources(${LIB_NAME}
    PUBLIC
    ${INCLUDE_DIR}/mygame/chess/table/Board.hpp
    ${INCLUDE_DIR}/mygame/chess/table/BoardSetter.hpp
    ${INCLUDE_DIR}/mygame/chess/table/CapturedFiguresArea.hpp
    ${INCLUDE_DIR}/mygame/chess/table/File.hpp
    ${INCLUDE_DIR}/mygame/chess/table/Rank.hpp
    ${INCLUDE_DIR}/mygame/chess/table/Table.hpp

    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Board.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BoardSetter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CapturedFiguresArea.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/File.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rank.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Table.cpp
    )

target_include_directories(${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
    )

target_compile_options(${LIB_NAME} PUBLIC -Werror -Wall -Wextra)