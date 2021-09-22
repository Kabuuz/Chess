set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(application)
add_subdirectory(chess)
add_subdirectory(temp)

add_library(mainlib STATIC)

target_link_libraries(mainlib PUBLIC
    temp_lib
    application_lib
    chess_app_lib
    chess_figure_lib
    chess_table_lib
    )

set(SOURCE_FILES
    ./main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system)
target_link_libraries(${PROJECT_NAME} PUBLIC mainlib)
