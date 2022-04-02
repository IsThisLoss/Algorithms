#include <gtest/gtest.h>

#include <LevenshteinDistance.h>

namespace StringUtils {

TEST(LevenshteinDistance, Empty) {
  const auto result = LevenshteinDistance("", "");
  ASSERT_EQ(result, 0);
}

TEST(LevenshteinDistance, LhsEmpty) {
  const auto result = LevenshteinDistance("", "a");
  ASSERT_EQ(result, 1);
}

TEST(LevenshteinDistance, RhsEmpty) {
  const auto result = LevenshteinDistance("b", "");
  ASSERT_EQ(result, 1);
}

TEST(LevenshteinDistance, EqualStrings) {
  const auto result = LevenshteinDistance("aab", "aab");
  ASSERT_EQ(result, 0);
}

TEST(LevenshteinDistance, Generic) {
  const auto result = LevenshteinDistance("bep", "eph");
  ASSERT_EQ(result, 2);
}

TEST(LevenshteinDistance, ComplitlyDifferent) {
  const auto result = LevenshteinDistance("abcde", "vwxyz");
  ASSERT_EQ(result, 5);
}

TEST(LevenshteinDistance, DifferentLengthLhsless) {
  const auto result = LevenshteinDistance("ab", "bcde");
  ASSERT_EQ(result, 4);
}

TEST(LevenshteinDistance, DifferentLengthRhsless) {
  const auto result = LevenshteinDistance("abcdefgh", "el");
  ASSERT_EQ(result, 7);
}

}
