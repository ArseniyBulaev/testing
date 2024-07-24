#include "gtest/gtest.h"
#include "Money.h"
#include "Expression.h"
#include "Bank.h"
#include "Sum.h"
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

TEST(moneyTest, testSimpleAddition) {
    //arrange
    Money five = Money::dollar(5);
    Expression * sum = five.plus(five);
    Bank bank;
    Money reduced = bank.reduce(*sum, "USD");
    //assert
    EXPECT_EQ(reduced, Money::dollar(10)); 
    //clear
    delete sum;   
}

TEST(moneyTest, testPlusReturnsSum){
    Money five = Money::dollar(5);
    Expression * result = five.plus(five);
    Sum * sum = dynamic_cast<Sum *>(result);
    //assert
    EXPECT_EQ(sum->augend, five);
    EXPECT_EQ(sum->addend, five);
    //clear
    delete sum;
}

TEST(moneyTest, testReduceSum){
    const Expression & sum = Sum(Money::dollar(3), Money::dollar(4));
    Bank bank;
    Money reduced = bank.reduce(sum, "USD");
    EXPECT_EQ(Money::dollar(7), reduced);
}

TEST(moneyTest, testReduceMoney){
    Bank bank;
    Money reduced = bank.reduce(Money::dollar(1), "USD");
    EXPECT_EQ(reduced, Money::dollar(1));
}