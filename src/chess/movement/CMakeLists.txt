set(LIB_NAME chess_movement_lib)

add_library(${LIB_NAME} OBJECT)

target_sources(${LIB_NAME}
    PUBLIC
    ${INCLUDE_DIR}/mygame/chess/movement/BishopMoveChecker.hpp
    ${INCLUDE_DIR}/mygame/chess/movement/CombinedMoveChecker.hpp
    ${INCLUDE_DIR}/mygame/chess/movement/IMoveChecker.hpp
    ${INCLUDE_DIR}/mygame/chess/movement/KnightMoveChecker.hpp
    ${INCLUDE_DIR}/mygame/chess/movement/PawnMoveChecker.hpp
    ${INCLUDE_DIR}/mygame/chess/movement/RookMoveChecker.hpp

    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/BishopMoveChecker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CombinedMoveChecker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/KnightMoveChecker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PawnMoveChecker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RookMoveChecker.cpp
    )

target_include_directories(${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
    )

target_compile_options(${LIB_NAME} PUBLIC -Werror -Wall -Wextra)
