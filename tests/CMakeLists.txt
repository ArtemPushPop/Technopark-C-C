include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Create binaries of tests

add_executable(test_car_low_level test_car_low_level.cpp)
target_link_libraries(test_car_low_level gtest_main)
target_link_libraries(test_car_low_level car)

add_executable(test_cars_lib test_cars_lib.cpp)
target_link_libraries(test_cars_lib gtest_main)
target_link_libraries(test_cars_lib car)

include_directories("${PROJECT_FOLDER}/include")