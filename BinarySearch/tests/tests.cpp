#include <gtest/gtest.h>

#include "BinarySearch.h"

TEST(BinarySearch, Empty) {
    std::vector<int> array{};
    auto it = BinarySearch::BinarySearch(array, 1);
    ASSERT_EQ(it, array.end());
}

TEST(BinarySearch, OneElement) {
    std::vector<int> array{1};
    auto it = BinarySearch::BinarySearch(array, 1);
    ASSERT_EQ(it, array.begin());
}

TEST(BinarySearch, TwoElementsBegin) {
    std::vector<int> array{1, 2};
    auto it = BinarySearch::BinarySearch(array, 1);
    ASSERT_EQ(it, array.begin());
}

TEST(BinarySearch, TwoElementsEnd) {
    std::vector<int> array{1, 2};
    auto it = BinarySearch::BinarySearch(array, 2);
    ASSERT_EQ(it, std::next(array.begin()));
}

TEST(BinarySearch, Array) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    auto it = BinarySearch::BinarySearch(array, 4);
    ASSERT_NE(it, array.end());
    ASSERT_EQ(*it, 4);
}

TEST(BinarySearch, ArrayAll) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    for (size_t i = 0; i < array.size(); i++) {
        auto it = BinarySearch::BinarySearch(array, i+1);
        ASSERT_EQ(it, std::next(array.begin(), i));
    }
}

TEST(BinarySearch, ElementNotFound) {
    std::vector<int> array{1, 2, 3, 4, 6, 7};
    auto it = BinarySearch::BinarySearch(array, 5);
    ASSERT_EQ(it, array.end());
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}