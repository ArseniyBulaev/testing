#include "gtest/gtest.h"
#include "Money.h"

TEST(dollarTest, multiplicationTest) {
    //arrange
    Money * five = Money::dollar(5);
    Money * ten = Money::dollar(10);
    Money * fifteen = Money::dollar(15);
    //act
    Money * five_times_two = five->times(2);
    Money * five_time_three = five->times(3);
    //assert
    EXPECT_EQ (*five_times_two, *ten);
    EXPECT_EQ (*five_time_three, *fifteen);
    //clear
    delete five_times_two;
    delete five_time_three;
    delete five;
    delete ten;
    delete fifteen;
}

TEST(dollarTest, equalTest) {
    //arrange
    Money * five_dollar = Money::dollar(5);
    Money * another_five_dollar = Money::dollar(5);
    Money * six_dollar = Money::dollar(6);
    Money * five_franc = Money::franc(5);
    //assert
    EXPECT_TRUE(five_dollar->equals(*another_five_dollar));
    EXPECT_FALSE(five_dollar->equals(*six_dollar)); 
    EXPECT_FALSE(five_dollar->equals(*five_franc));
    //clear
    delete five_dollar;
    delete another_five_dollar;
    delete six_dollar;
    delete five_franc;
}