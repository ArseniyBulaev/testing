#include "gtest/gtest.h"
#include "Dollar.h"

TEST(dollarTest, multiplicationTest) {
    //arrange
    Dollar five = Dollar(5);
    //act
    //assert
    EXPECT_EQ (five.times(2), Dollar(10));
    EXPECT_EQ (five.times(3), Dollar(15));
}

TEST(dollarTest, equalTest) {
    EXPECT_TRUE(Dollar(5).equals(Dollar(5)));
    EXPECT_FALSE(Dollar(5).equals(Dollar(6))); 
}