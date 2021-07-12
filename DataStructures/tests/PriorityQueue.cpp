#include <gtest/gtest.h>

#include "PriorityQueue.h"

TEST(PriorityQueue, isEmpty) {
  PriorityQueue<int> queue;
  ASSERT_TRUE(queue.isEmpty());
}

TEST(PriorityQueue, insert) {
  constexpr int ELEMENT = 10;
  PriorityQueue<int> queue;
  queue.insert(ELEMENT);
  ASSERT_FALSE(queue.isEmpty());
  ASSERT_EQ(queue.top(), ELEMENT);
}

TEST(PriorityQueue, pop) {
  constexpr int ELEMENT = 10;
  PriorityQueue<int> queue;
  queue.insert(ELEMENT);
  ASSERT_EQ(queue.pop(), ELEMENT);
  ASSERT_TRUE(queue.isEmpty());
}

TEST(PriorityQueue, priority) {
  PriorityQueue<int> queue;
  queue.insert(1);
  queue.insert(2);
  queue.insert(5);
  queue.insert(4);
  queue.insert(3);
  ASSERT_EQ(queue.top(), 5);
  ASSERT_FALSE(queue.isEmpty());
  ASSERT_EQ(queue.pop(), 5);
  ASSERT_FALSE(queue.isEmpty());
  ASSERT_EQ(queue.pop(), 4);
  ASSERT_FALSE(queue.isEmpty());
  ASSERT_EQ(queue.pop(), 3);
  ASSERT_FALSE(queue.isEmpty());
  ASSERT_EQ(queue.pop(), 2);
  ASSERT_FALSE(queue.isEmpty());
  ASSERT_EQ(queue.pop(), 1);
  ASSERT_TRUE(queue.isEmpty());
}
