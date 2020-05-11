#include <gtest/gtest.h>

int sum(int x, int y){
    return x+y;
}

TEST(MyTesting, first){
    EXPECT_EQ(true, true);
    EXPECT_EQ(1, sum(0, 1));
}