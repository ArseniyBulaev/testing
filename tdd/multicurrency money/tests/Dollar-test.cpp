#include "gtest/gtest.h"
#include "Dollar.h"

TEST(blaTest, test1) {
    //arrange
    Dollar five = Dollar(5);
    //act
    five.times(2);
    //assert
    EXPECT_EQ (five.amount,  10);
}