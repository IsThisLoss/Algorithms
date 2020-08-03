#include <gtest/gtest.h>

#include "QuickSort.h"

TEST(QuickSort, empty) {
    std::vector<int> data = {};
    quickSort(data.begin(), data.end());
    ASSERT_TRUE(data.empty());
}

TEST(QuickSort, one) {
    std::vector<int> data = {1};
    std::vector<int> expected = data;
    quickSort(data.begin(), data.end());
    ASSERT_EQ(data, expected);
}

TEST(QuickSort, sorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> expected = data;
    quickSort(data.begin(), data.end());
    ASSERT_EQ(data, expected);
}

TEST(QuickSort, quickSort) {
    std::vector<int> data = {5, 4, 1, 3, 2};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    quickSort(data.begin(), data.end());
    ASSERT_EQ(data, expected);
}

TEST(QuickSort, negativeNumbers) {
    std::vector<int> data = {5, 4, -1, -2, 0, 3, 1, 2};
    std::vector<int> expected = {-2, -1, 0, 1, 2, 3, 4, 5};
    quickSort(data.begin(), data.end());
    ASSERT_EQ(data, expected);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
