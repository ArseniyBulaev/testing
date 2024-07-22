#include "gtest/gtest.h"
#include "Money.h"
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