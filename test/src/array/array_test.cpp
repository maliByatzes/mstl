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
  mstd::array<char, 6> letters{ 'a', 'b', 'c', 'd', 'e', 'f' };  // NOLINT
  ASSERT_EQ(letters.back(), 'f');
}

TEST(ArrayTest, CheckConstBackFunc)
{
  const mstd::array<char, 6> letters{ 'a', 'b', 'c', 'd', 'e', 'f' };
  ASSERT_EQ(letters.back(), 'f');
}

TEST(ArrayTest, CheckDataFunc)
{
  mstd::array<int, 4> elems{ 2, 5, 8, 9 };  // NOLINT
  ASSERT_EQ(elems.data(), &elems[0]);       // NOLINT
}

TEST(ArrayTest, CheckConsDataFunc)
{
  const mstd::array<int, 4> elems{ 2, 5, 8, 9 };  // NOLINT
  ASSERT_EQ(elems.data(), &elems[0]);             // NOLINT
}

TEST(ArrayTest, CheckIterators)
{
  mstd::array<int, 4> numbers{ 5, 2, 3, 4 };  // NOLINT
  ASSERT_FALSE(numbers.begin() == numbers.end());
  ASSERT_FALSE(numbers.begin() == numbers.end());
  ASSERT_EQ(*(numbers.begin()), 5);
  ASSERT_EQ(*(numbers.cbegin()), 5);
}

TEST(ArrayTest, CheckEmptyFunc)
{
  mstd::array<int, 4> numbers{ 3, 1, 4, 1 };
  ASSERT_FALSE(numbers.empty());
}

TEST(ArrayTest, CheckSize)
{
  mstd::array<int, 4> numbers{ 2, 3, 4, 1 };
  ASSERT_EQ(numbers.size(), 4);
  ASSERT_EQ(numbers.max_size(), 4);
}

TEST(ArrayTest, CheckFillFunc)
{
  mstd::array<char, 3> letters{};
  letters.fill('b');
  ASSERT_EQ(letters.at(0), 'b');
  ASSERT_EQ(letters.at(1), 'b');
  ASSERT_EQ(letters.at(2), 'b');
}

TEST(ArrayTest, CheckOperators) {
  mstd::array<int, 3> alice{1, 2, 3};
  mstd::array<int, 3> bob{7, 8, 9}; //NOLINT
  mstd::array<int, 3> eve{1, 2, 3};

  // non-equal
  ASSERT_FALSE(alice == bob);
  ASSERT_TRUE(alice != bob);

  // equal
  ASSERT_TRUE(alice == eve);
  ASSERT_FALSE(alice != eve);
}

TEST(ArrayTest, CheckGetFunc) {
  mstd::array<int, 3> arr{1, 2, 3};
  ASSERT_EQ(mstd::get<0>(arr), 1);
  ASSERT_EQ(mstd::get<1>(arr), 2);
  ASSERT_EQ(mstd::get<2>(arr), 3);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
