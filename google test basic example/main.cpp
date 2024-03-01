#include <gtest/gtest.h>
#include <iostream>


TEST(TestGroupName, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}

TEST(TestGroupName, Subtest_2) {
  ASSERT_FALSE('b' == 'b');
  std::cout << "continue test after failure" << std::endl;
}

TEST(TestGroupName, Subset_3){
    ASSERT_EQ(1, 2);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}