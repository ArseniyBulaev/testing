#include "gtest/gtest.h"
#include "Franc.h"

TEST(francTest, multiplicationTest) {
    //arrange
    Franc five = Franc(5);
    //act
    //assert
    EXPECT_EQ (five.times(2), Franc(10));
    EXPECT_EQ (five.times(3), Franc(15));
}

TEST(francTest, equalTest) {
    EXPECT_TRUE(Franc(5).equal(Franc(5)));
    EXPECT_FALSE(Franc(5).equal(Franc(6))); 
}