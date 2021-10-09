cmake_minimum_required(VERSION 3.17)
project(IZ1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -ggdb3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Werror -Wpedantic -ggdb3 -O3")

set(PROJECT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/project)
set(DATA_FILE "${CMAKE_CURRENT_SOURCE_DIR}/data/data.txt")

add_executable(main "${PROJECT_FOLDER}/main.c")

#build libraries
add_subdirectory("${PROJECT_FOLDER}/src/")
target_link_libraries(main car)
include_directories(${PROJECT_FOLDER}/include/
                    )

#configure main.h (data file setting)
configure_file("${PROJECT_FOLDER}/include/main.h.in" "${PROJECT_FOLDER}/include/main.h")

#tests

option(TEST "Build tests" OFF)
if (TEST)
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif ()