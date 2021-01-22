#include <gtest/gtest.h>

#include "QuickSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "HeapSort.h"

namespace {
    using Algorithm = std::function<void(std::vector<int>&)>;
    std::vector<Algorithm> sortingAlgorithms = {
            quickSort<std::vector<int>>,
            threeWayQuickSort<std::vector<int>>,
            insertionSort<std::vector<int>>,
            mergeSort<std::vector<int>>,
            heapSort<std::vector<int>>,
            recursiveMergeSort<std::vector<int>>,
    };
}

class SortTest : public ::testing::TestWithParam<Algorithm> {};

TEST_P(SortTest, empty) {
    std::vector<int> data = {};
    auto sortingAlgorithm = GetParam();
    sortingAlgorithm(data);
    ASSERT_TRUE(data.empty());
}

TEST_P(SortTest, one) {
    std::vector<int> data = {1};
    std::vector<int> expected = data;
    auto sortingAlgorithm = GetParam();
    sortingAlgorithm(data);
    ASSERT_EQ(data, expected);
}

TEST_P(SortTest, sorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> expected = data;
    auto sortingAlgorithm = GetParam();
    sortingAlgorithm(data);
    ASSERT_EQ(data, expected);
}

TEST_P(SortTest, quickSort) {
    std::vector<int> data = {5, 4, 1, 3, 2};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    auto sortingAlgorithm = GetParam();
    sortingAlgorithm(data);
    ASSERT_EQ(data, expected);
}

TEST_P(SortTest, negativeNumbers) {
    std::vector<int> data = {5, 4, -1, -2, 0, 3, 1, 2};
    std::vector<int> expected = {-2, -1, 0, 1, 2, 3, 4, 5};
    auto sortingAlgorithm = GetParam();
    sortingAlgorithm(data);
    ASSERT_EQ(data, expected);
}

INSTANTIATE_TEST_SUITE_P(
        Sorts,
        SortTest,
        ::testing::ValuesIn(sortingAlgorithms)
        );

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}