#include "mstd/array/array.hpp"

#include <gtest/gtest.h>

TEST(ArrayTest, CheckAtFunc)
{
  mstd::array<int, 3> data = { 5, 2, 6 };  // NOLINT
  ASSERT_EQ(data.at(0), 5);
  EXPECT_THROW(data.at(4), std::out_of_range);
}

TEST(ArrayTest, CheckConstAtFunc)
{
  const mstd::array<double, 4> data = { 4.56, 1.32, 7.23, 4.0 };
  ASSERT_EQ(data.at(1), 1.32);
  EXPECT_THROW(data.at(5), std::out_of_range);
}

TEST(ArrayTest, CheckSubscriptFunc)
{
  mstd::array<std::string, 3> data = { "Hello", "World", "!" };
  ASSERT_EQ(data[2], "!");
}

TEST(ArrayTest, CheckConstSubscriptFunc)
{
  const mstd::array<std::string, 3> data = { "Hello", "World", "!" };
  ASSERT_EQ(data[2], "!");
}

TEST(ArrayTest, CheckFrontFunc)
{
  mstd::array<int, 3> data = { 4, 2, 6 };  // NOLINT
  ASSERT_EQ(data.front(), 4);
}

TEST(ArrayTest, CheckConstFrontFunc)
{
  const mstd::array<int, 3> data = { 4, 2, 6 };  // NOLINT
  ASSERT_EQ(data.front(), 4);
}

TEST(ArrayTest, CheckBackFunc)
{
  mstd::array<char, 6> letters{ 'a', 'b', 'c', 'd', 'e', 'f' }; // NOLINT
  ASSERT_EQ(letters.back(), 'f');
}

TEST(ArrayTest, CheckConstBackFunc)
{
  const mstd::array<char, 6> letters{ 'a', 'b', 'c', 'd', 'e', 'f' };
  ASSERT_EQ(letters.back(), 'f');
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
