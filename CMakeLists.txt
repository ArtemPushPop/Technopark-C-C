cmake_minimum_required(VERSION 3.15)
project(IZ1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -ggdb3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Werror -Wpedantic -ggdb3 -O3")

set(PROJECT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/project)
set(DATA_FILE "${CMAKE_CURRENT_SOURCE_DIR}/data/data.txt")

add_executable(main "${PROJECT_FOLDER}/main.c")

#build libraries
add_subdirectory("${PROJECT_FOLDER}/src/")
target_link_libraries(main car)
include_directories(${PROJECT_FOLDER}/include/)

#configure main.h (data file setting)
configure_file("${PROJECT_FOLDER}/include/main.h.in" "${PROJECT_FOLDER}/include/main.h")

#tests

option(TEST "Build tests" OFF)
if (TEST)
    include(CTest)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    # Create binaries of tests

    add_executable(test_car_low_level tests/test_car_low_level.cpp)
    target_link_libraries(test_car_low_level gtest_main)
    target_link_libraries(test_car_low_level car)
    add_test(NAME AllTestsInCarLowLevel COMMAND test_car_low_level)


    add_executable(test_cars_lib tests/test_cars_lib.cpp)
    target_link_libraries(test_cars_lib gtest_main)
    target_link_libraries(test_cars_lib car)
    add_test(NAME AllTestsInCarsLib COMMAND test_cars_lib)

endif ()