#include <gtest/gtest.h>

#include "BinarySearch.h"

namespace BinarySearch {

TEST(BinarySearch, Empty) {
    std::vector<int> array{};
    auto it = BinarySearch(array, 1);
    ASSERT_EQ(it, array.end());
}

TEST(BinarySearch, OneElement) {
    std::vector<int> array{1};
    auto it = BinarySearch(array, 1);
    ASSERT_EQ(it, array.begin());
}

TEST(BinarySearch, TwoElementsBegin) {
    std::vector<int> array{1, 2};
    auto it = BinarySearch(array, 1);
    ASSERT_EQ(it, array.begin());
}

TEST(BinarySearch, TwoElementsEnd) {
    std::vector<int> array{1, 2};
    auto it = BinarySearch(array, 2);
    ASSERT_EQ(it, std::next(array.begin()));
}

TEST(BinarySearch, Array) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    auto it = BinarySearch(array, 4);
    ASSERT_NE(it, array.end());
    ASSERT_EQ(*it, 4);
}

TEST(BinarySearch, ArrayAll) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    for (size_t i = 0; i < array.size(); i++) {
        auto it = BinarySearch(array, i+1);
        ASSERT_EQ(it, std::next(array.begin(), i));
    }
}

TEST(BinarySearch, ElementNotFound) {
    std::vector<int> array{1, 2, 3, 4, 6, 7};
    auto it = BinarySearch(array, 5);
    ASSERT_EQ(it, array.end());
}

TEST(BinarySearch, ElementNotFoundGreater) {
    std::vector<int> array{1, 2, 3, 4, 6, 7};
    auto it = BinarySearch(array, 10);
    ASSERT_EQ(it, array.end());
}

TEST(BinarySearch, ElementNotFoundLesser) {
    std::vector<int> array{1, 2, 3, 4, 6, 7};
    auto it = BinarySearch(array, -10);
    ASSERT_EQ(it, array.end());
}

}
