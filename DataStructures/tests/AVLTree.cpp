#include <gtest/gtest.h>

#include "AVLTree.h"

TEST(AVLTree, empty) {
  AVLTree<int> tree;
  ASSERT_EQ(tree.find(1), nullptr);
  tree.remove(1); // no errors
  ASSERT_EQ(tree.getHeight(), 0);
}

TEST(AVLTree, insert) {
  AVLTree<int> tree;
  tree.insert(1);
  const auto* val = tree.find(1);
  ASSERT_NE(val, nullptr);
  ASSERT_EQ(*val, 1);
}

TEST(AVLTree, remove) {
  AVLTree<int> tree;
  tree.insert(1);
  const auto* val = tree.find(1);
  ASSERT_NE(val, nullptr);
  tree.remove(1);
  val = tree.find(1);
  ASSERT_EQ(val, nullptr);
}

TEST(AVLTree, getHeight) {
  AVLTree<int> tree;
  tree.insert(1);
  ASSERT_EQ(tree.getHeight(), 1);
  tree.insert(2);
  ASSERT_EQ(tree.getHeight(), 2);
  tree.insert(3);
  ASSERT_EQ(tree.getHeight(), 2);
  tree.insert(0);
  ASSERT_EQ(tree.getHeight(), 3);
  tree.insert(4);
  ASSERT_EQ(tree.getHeight(), 3);
}

TEST(AVLTree, insertDuplicates) {
  AVLTree<int> tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(1);
  ASSERT_NE(tree.find(1), nullptr);
  ASSERT_NE(tree.find(2), nullptr);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
