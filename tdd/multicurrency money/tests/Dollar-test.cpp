#include "gtest/gtest.h"
#include "Dollar.h"

TEST(dollarTest, multiplicationTest) {
    //arrange
    Dollar five = Dollar(5);
    //act
    Dollar ten = five.times(2);
    Dollar fifteen = five.times(3);
    //assert
    EXPECT_EQ (five.amount, 5);
    EXPECT_EQ (ten.amount,  10);
    EXPECT_EQ (fifteen.amount, 15);
}

TEST(dollarTest, equalTest) {
    EXPECT_TRUE(Dollar(5).equal(Dollar(5)));
    EXPECT_FALSE(Dollar(5).equal(Dollar(6))); 
}