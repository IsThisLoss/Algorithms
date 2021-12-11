#include <gtest/gtest.h>

#include "KmpSearch.h"
#include "StringSplit.h"

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

TEST(StringSplit, EmptyInput) {
  const std::string input = "";
  const auto result = StringSplit::split(input, ',');
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(result.front(), input);
}

TEST(StringSplit, InvalidDelimeter) {
  const std::string input = "a,b,c";
  const auto result = StringSplit::split(input, '.');
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(result.front(), input);
}

TEST(StringSplit, SplitOneAndEmpty) {
  const std::string input = "a,";
  const auto result = StringSplit::split(input, ',');
  ASSERT_EQ(result.size(), 2);
  ASSERT_EQ(result.front(), "a");
  ASSERT_EQ(result.back(), "");
}

TEST(StringSplit, SplitTwo) {
  const std::string input = "a,b";
  const auto result = StringSplit::split(input, ',');
  ASSERT_EQ(result.size(), 2);
  ASSERT_EQ(result.front(), "a");
  ASSERT_EQ(result.back(), "b");
}

TEST(StringSplit, SplitMany) {
  const std::string input = "a,bbb,cccc,ddddd,e";
  const auto result = StringSplit::split(input, ',');
  ASSERT_EQ(result.size(), 5);
  std::vector<std::string> expected_tokens{
    "a", "bbb", "cccc", "ddddd", "e"
  };
  size_t i = 0;
  for (const auto& token : result) {
    ASSERT_EQ(token, expected_tokens[i++]);
  }
}
