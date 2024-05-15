#include "mstd/array/array.hpp"
#include <gtest/gtest.h>
#include <array>

TEST(ArrayTest, CheckAtFunc)
{
  mstd::array<int, 3> data = { 5, 2, 6 }; // NOLINT
  ASSERT_EQ(data.at(0), 5);
  EXPECT_THROW(data.at(4), std::out_of_range);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
