#include <gtest/gtest.h>

#include "StringSplit.h"

namespace StringUtils {

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

}
