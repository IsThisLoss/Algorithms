#include <gtest/gtest.h>
#include "Xrange.h"

using namespace Xrange;

TEST(Xrange, onlyStop) {
    std::vector<int> data;
    std::vector<int> expected = {0, 1, 2, 3, 4};
    for (int i : xrange(5)) {
        data.push_back(i);
    }
    ASSERT_EQ(data, expected);
}

TEST(Xrange, range) {
    std::vector<int> data;
    std::vector<int> expected = {1, 2, 3, 4};
    for (int i : xrange(1,5)) {
        data.push_back(i);
    }
    ASSERT_EQ(data, expected);
}

TEST(Xrange, withStep) {
    std::vector<int> data;
    std::vector<int> expected = {1, 3};
    for (int i : xrange(1,5, 2)) {
        data.push_back(i);
    }
    ASSERT_EQ(data, expected);
}

TEST(Xrange, negativeStep) {
    std::vector<int> data;
    std::vector<int> expected = {1, 0, -1, -2, -3, -4};
    for (int i : xrange(1,-5, -1)) {
        data.push_back(i);
    }
    ASSERT_EQ(data, expected);
}
