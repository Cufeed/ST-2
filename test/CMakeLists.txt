add_executable(Tests
    tests.cpp
    AllTests.cpp
)

target_include_directories(Tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Явно указываем линковать динамическую CRT для GoogleTest
target_compile_options(gtest PRIVATE "/MD$<$<CONFIG:Debug>:d>")
target_compile_options(gtest_main PRIVATE "/MD$<$<CONFIG:Debug>:d>")

target_link_libraries(Tests
    CircleLib
    gtest
    gtest_main
)

enable_testing()
add_test(NAME CircleTests COMMAND Tests)