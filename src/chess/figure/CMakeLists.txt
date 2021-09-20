set(LIB_NAME chess_figure_lib)

add_library(${LIB_NAME} OBJECT)

target_sources(${LIB_NAME}
    PUBLIC
    ${INCLUDE_DIR}/mygame/chess/figure/FigureBase.hpp
    ${INCLUDE_DIR}/mygame/chess/figure/BishopFigure.hpp
    ${INCLUDE_DIR}/mygame/chess/figure/KnightFigure.hpp
    ${INCLUDE_DIR}/mygame/chess/figure/PawnFigure.hpp
    ${INCLUDE_DIR}/mygame/chess/figure/RookFigure.hpp

    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/FigureBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BishopFigure.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/KnightFigure.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PawnFigure.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RookFigure.cpp
    )

target_include_directories(${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
    )

target_compile_options(${LIB_NAME} PUBLIC -Werror -Wall -Wextra)