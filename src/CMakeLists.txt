set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(temp)

add_library(mainlib STATIC)

target_link_libraries(mainlib PUBLIC
    temp_lib
    )

set(SOURCE_FILES
    ./main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics)
target_link_libraries(${PROJECT_NAME} PUBLIC mainlib)
