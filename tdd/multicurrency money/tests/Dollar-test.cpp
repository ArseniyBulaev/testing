#include "gtest/gtest.h"
#include "Dollar.h"

TEST(dollarTest, multiplicationTest) {
    //arrange
    Dollar five = Dollar(5);
    //act
    Money * five_times_two = five.times(2);
    Money * five_time_three = five.times(3);
    //assert
    EXPECT_EQ (*five_times_two, Dollar(10));
    EXPECT_EQ (*five_time_three, Dollar(15));
    //clear
    delete five_times_two;
    delete five_time_three;
}

TEST(dollarTest, equalTest) {
    EXPECT_TRUE(Dollar(5).equals(Dollar(5)));
    EXPECT_FALSE(Dollar(5).equals(Dollar(6))); 
}