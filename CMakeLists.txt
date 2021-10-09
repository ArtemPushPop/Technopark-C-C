cmake_minimum_required(VERSION 3.14)
project(IZ1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -ggdb3")

set(PROJECT_FOLDER ./project/)

add_executable(main "${PROJECT_FOLDER}main.c")

#build libraries
add_subdirectory("${PROJECT_FOLDER}src/")

include_directories("${PROJECT_FOLDER}include/")

target_link_libraries(main car)

option(TEST "Build tests" OFF)
if (TEST)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    # Create binaries of tests
    add_executable(mmfile_tests tests/test_hello.cpp)
    target_link_libraries(mmfile_tests gtest_main)
    target_link_libraries(mmfile_tests test_lib)
endif ()