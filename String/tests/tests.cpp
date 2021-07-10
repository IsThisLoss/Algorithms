#include <gtest/gtest.h>
#include "String.h"

TEST(String, empty) {
  String s;
  ASSERT_TRUE(s.empty());
  ASSERT_EQ(s.size(), 0);
}

TEST(String, ctor) {
  String s{"Hello world"};
  ASSERT_FALSE(s.empty());
  ASSERT_EQ(s.size(), 11);
}

TEST(String, clear) {
  String s{"Hello world"};
  s.clear();
  ASSERT_TRUE(s.empty());
  ASSERT_EQ(s.size(), 0);
}

TEST(String, reserve) {
  constexpr size_t CAPACITY = 100;
  String s;
  s.reserve(CAPACITY);
  ASSERT_TRUE(s.capacity() <= CAPACITY);
}

TEST(String, pushBack) {
  constexpr char LETTER = 'a';
  String s;
  s.pushBack(LETTER);
  ASSERT_EQ(s.size(), 1);
  ASSERT_EQ(s[0], LETTER);
  ASSERT_EQ(s.at(0), LETTER);
}

TEST(String, c_str) {
  constexpr const char* DATA = "Hello world";
  String s{DATA};
  ASSERT_STREQ(s.c_str(), DATA);
}

TEST(String, data) {
  String s{"Hello"};
  *s.data() = 'h';
  ASSERT_STREQ(s.c_str(), "hello");
}

TEST(String, eq) {
  String lhs{"Hello"};
  String rhs{"Hello"};
  ASSERT_EQ(lhs.size(), rhs.size());
  ASSERT_EQ(lhs, rhs);
}

TEST(String, copy) {
  String lhs{"Hello"};
  String rhs{"world"};
  lhs = rhs;
  ASSERT_STREQ(lhs.c_str(), "world");
}

TEST(String, move) {
  String lhs{"Hello"};
  String rhs{"world"};
  lhs = std::move(rhs);
  ASSERT_STREQ(lhs.c_str(), "world");
}

TEST(String, copySubstring) {
  String lhs{"Hello"};
  String rhs{lhs, 1, 1};
  ASSERT_STREQ(rhs.c_str(), "e");
}
