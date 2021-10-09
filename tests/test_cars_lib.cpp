#include <iostream>
#include "gtest/gtest.h"


extern "C" {
#include "cars_functions.h"
}

TEST(test_hello, hello_prints){
    ASSERT_TRUE(1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}