#include "gtest/gtest.h"
#include "Money.h"
#include "Franc.h"
#include <string>

TEST(moneyTest, testCurrency){
    // arrange
    EXPECT_EQ(std::string("USD"), Money::dollar(1).currency());
    EXPECT_EQ(std::string("CHF"), Money::franc(2).currency());
    // clear
}

TEST(moneyTest, testDifferentClassEquality){
    EXPECT_TRUE(Money(10,"CHF").equals(Franc(10, "CHF")));
}