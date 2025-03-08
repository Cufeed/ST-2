add_library(CircleLib
    circle.cpp
    tasks.cpp
)

target_include_directories(CircleLib
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

add_executable(MainApp main.cpp)
target_link_libraries(MainApp CircleLib)