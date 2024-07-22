#include "gtest/gtest.h"
#include "Money.h"
#include <string>

TEST(moneyTest, testCurrency){
    // arrange
    EXPECT_EQ(std::string("USD"), Money::dollar(1).currency());
    EXPECT_EQ(std::string("CHF"), Money::franc(2).currency());
    // clear
}

TEST(moneyTest, multiplicationTest) {
    //arrange
    Money five = Money::dollar(5);
    //act
    //assert
    EXPECT_EQ (five.times(2), Money::dollar(10));
    EXPECT_EQ (five.times(3), Money::dollar(15));
    //clear
}

TEST(moneyTest, equalTest) {
    //arrange
    //assert
    EXPECT_TRUE(Money::dollar(5).equals(Money::dollar(5)));
    EXPECT_FALSE(Money::dollar(5).equals(Money::dollar(6))); 
    EXPECT_FALSE(Money::dollar(5).equals(Money::franc(5)));
    //clear
}