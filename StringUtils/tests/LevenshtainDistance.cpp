#include <gtest/gtest.h>

#include <LevenshtainDistance.h>

TEST(levenshtainDistance, Empty) {
  const auto result = levenshtainDistance("", "");
  ASSERT_EQ(result, 0);
}

TEST(levenshtainDistance, LhsEmpty) {
  const auto result = levenshtainDistance("", "a");
  ASSERT_EQ(result, 1);
}

TEST(levenshtainDistance, RhsEmpty) {
  const auto result = levenshtainDistance("b", "");
  ASSERT_EQ(result, 1);
}

TEST(levenshtainDistance, EqualStrings) {
  const auto result = levenshtainDistance("aab", "aab");
  ASSERT_EQ(result, 0);
}

TEST(levenshtainDistance, Generic) {
  const auto result = levenshtainDistance("bep", "eph");
  ASSERT_EQ(result, 2);
}

TEST(levenshtainDistance, ComplitlyDifferent) {
  const auto result = levenshtainDistance("abcde", "vwxyz");
  ASSERT_EQ(result, 5);
}

TEST(levenshtainDistance, DifferentLengthLhsless) {
  const auto result = levenshtainDistance("ab", "bcde");
  ASSERT_EQ(result, 4);
}

TEST(levenshtainDistance, DifferentLengthRhsless) {
  const auto result = levenshtainDistance("abcdefgh", "el");
  ASSERT_EQ(result, 7);
}
