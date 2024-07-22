#include "gtest/gtest.h"
#include "Franc.h"

TEST(francTest, multiplicationTest) {
    //arrange
    Franc five = Franc(5);
    //act
    Money * five_times_two = five.times(2);
    Money * five_time_three = five.times(3);
    //assert
    EXPECT_EQ (*five_times_two, Franc(10));
    EXPECT_EQ (*five_time_three, Franc(15));
    //clear
    delete five_times_two;
    delete five_time_three;
}

TEST(francTest, equalTest) {
    EXPECT_TRUE(Franc(5).equals(Franc(5)));
    EXPECT_FALSE(Franc(5).equals(Franc(6))); 
}