#include "gtest/gtest.h"
#include "Money.h"

TEST(dollarTest, multiplicationTest) {
    //arrange
    Money five = Money::dollar(5);
    //act
    //assert
    EXPECT_EQ (five.times(2), Money::dollar(10));
    EXPECT_EQ (five.times(3), Money::dollar(15));
    //clear
}

TEST(dollarTest, equalTest) {
    //arrange
    //assert
    EXPECT_TRUE(Money::dollar(5).equals(Money::dollar(5)));
    EXPECT_FALSE(Money::dollar(5).equals(Money::dollar(6))); 
    EXPECT_FALSE(Money::dollar(5).equals(Money::franc(5)));
    //clear
}