#include <gtest/gtest.h>

#include "HashTable.h"

TEST(HashTable, isEmpty) {
  HashTable<std::string> hash;
  ASSERT_TRUE(hash.isEmpty()); 
  ASSERT_EQ(hash.size(), 0); 
}

TEST(HashTable, insert) {
  HashTable<std::string> hash;
  hash.insert("hello");
  ASSERT_FALSE(hash.isEmpty()); 
  ASSERT_EQ(hash.size(), 1); 
}

TEST(HashTable, find) {
  static const std::string HELLO{"hello"};
  HashTable<std::string> hash;
  hash.insert(HELLO);
  ASSERT_TRUE(hash.find(HELLO));
}

TEST(HashTable, remove) {
  static const std::string HELLO{"hello"};
  HashTable<std::string> hash;
  hash.insert(HELLO);
  ASSERT_TRUE(hash.remove(HELLO));
  ASSERT_FALSE(hash.find(HELLO));
  ASSERT_TRUE(hash.isEmpty());
  ASSERT_EQ(hash.size(), 0);
}
