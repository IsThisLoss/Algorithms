#include <gtest/gtest.h>

#include <BKTree.h>

TEST(BKTree, Empty) {
  BKTree bkTree;
  const auto result = bkTree.find("hello", 1);
  ASSERT_TRUE(result.empty());
}

TEST(BKTree, ExactMatch) {
  const std::string HELLO = "hello";
  BKTree bkTree;
  bkTree.insert(HELLO);
  const auto result = bkTree.find(HELLO, 1);
  ASSERT_FALSE(result.empty());
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(result.front(), HELLO);
}

TEST(BKTree, InExactMatch) {
  BKTree bkTree;
  bkTree.insert("abc");
  const auto result = bkTree.find("ab", 1);
  ASSERT_FALSE(result.empty());
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(result.front(), "abc");
}

TEST(BKTree, Threshold) {
  BKTree bkTree;
  bkTree.insert("abcde");
  ASSERT_EQ(bkTree.find("ab", 1).size(), 0);
  ASSERT_EQ(bkTree.find("ab", 2).size(), 0);
  ASSERT_EQ(bkTree.find("ab", 3).size(), 1);
  ASSERT_EQ(bkTree.find("ab", 4).size(), 1);
}

TEST(BKTree, Complex) {
  BKTree bkTree;
  bkTree.insert("book");
  bkTree.insert("books");
  bkTree.insert("cake");
  bkTree.insert("boo");
  bkTree.insert("boon");
  bkTree.insert("cook");
  bkTree.insert("cape");
  bkTree.insert("cart");
  auto result = bkTree.find("boo", 2);
  ASSERT_EQ(result.size(), 5);
  sort(result.begin(), result.end());
  const std::vector<std::string> expected{"boo", "book", "books", "boon", "cook"};
  ASSERT_EQ(result, expected);
}
