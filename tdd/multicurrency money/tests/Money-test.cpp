#include "gtest/gtest.h"
#include "Money.h"
#include "Franc.h"
#include <string>

TEST(moneyTest, testCurrency){
    // arrange
    Money * dollar = Money::dollar(1);
    Money * franc = Money::franc(2);
    EXPECT_EQ(std::string("USD"), dollar->currency());
    EXPECT_EQ(std::string("CHF"), franc->currency());
    // clear
    delete dollar;
    delete franc;
}

TEST(moneyTest, testDifferentClassEquality){
    EXPECT_TRUE(Money(10,"CHF").equals(Franc(10, "CHF")));
}