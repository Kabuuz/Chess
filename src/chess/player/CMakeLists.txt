set(LIB_NAME chess_player_lib)

add_library(${LIB_NAME} OBJECT)

target_sources(${LIB_NAME}
        PUBLIC
        ${INCLUDE_DIR}/mygame/chess/player/IPlayer.hpp
        ${INCLUDE_DIR}/mygame/chess/player/Player.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp
        )

target_include_directories(${LIB_NAME}
        PUBLIC
        ${HEADERS_DIR}
        )

target_compile_options(${LIB_NAME} PUBLIC -Werror -Wall -Wextra)
