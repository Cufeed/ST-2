cmake_minimum_required(VERSION 3.15)
project(CircleProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем использовать динамическую версию Runtime Library
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(test)