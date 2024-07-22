#include "gtest/gtest.h"
#include "Money.h"

TEST(francTest, multiplicationTest) {
    //arrange
    Money * five = Money::franc(5);
    Money * ten = Money::franc(10);
    Money * fifteen = Money::franc(15);
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

TEST(francTest, equalTest) {
    //arrange
    Money * five_franc = Money::franc(5);
    Money * another_five_franc = Money::franc(5);
    Money * six_franc = Money::franc(6);
    Money * five_dollar = Money::dollar(5);
    //assert
    EXPECT_TRUE(five_franc->equals(*another_five_franc));
    EXPECT_FALSE(five_franc->equals(*six_franc));
    EXPECT_FALSE(five_franc->equals(*five_dollar)); 
    //clear
    delete five_franc;
    delete another_five_franc;
    delete six_franc;
    delete five_dollar;
}