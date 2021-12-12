#include <gtest/gtest.h>

#include "KmpSearch.h"

TEST(KmpSearch, EmptyPattern) {
  const auto result = KmpSearch("", "text");
  ASSERT_EQ(result, std::string::npos);
}

TEST(KmpSearch, EmptyText) {
  const auto result = KmpSearch("pattern", "");
  ASSERT_EQ(result, std::string::npos);
}

TEST(KmpSearch, OneToken) {
  const auto result = KmpSearch("x", "text");
  ASSERT_EQ(result, 2);
}

TEST(KmpSearch, Substring) {
  const auto result = KmpSearch("ex", "text");
  ASSERT_EQ(result, 1);
}

TEST(KmpSearch, NotFoundSubstring) {
  const auto result = KmpSearch("abc", "text");
  ASSERT_EQ(result, std::string::npos);
}

TEST(KmpSearch, EndSubstringFound) {
  const auto result = KmpSearch("xt", "text");
  ASSERT_EQ(result, 2);
}

TEST(KmpSearch, EndSubstring) {
  const auto result = KmpSearch("xtt", "text");
  ASSERT_EQ(result, std::string::npos);
}
