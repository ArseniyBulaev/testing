#include "gtest/gtest.h"
#include "Money.h"

TEST(francTest, multiplicationTest) {
    //arrange
    Money five = Money::franc(5);
    //act
    //assert
    EXPECT_EQ (five.times(2), Money::franc(10));
    EXPECT_EQ (five.times(3), Money::franc(15));
    //clear
}

TEST(francTest, equalTest) {
    //arrange
    //assert
    EXPECT_TRUE(Money::franc(5).equals(Money::franc(5)));
    EXPECT_FALSE(Money::franc(5).equals(Money::franc(6)));
    EXPECT_FALSE(Money::franc(5).equals(Money::dollar(5))); 
    //clear
}