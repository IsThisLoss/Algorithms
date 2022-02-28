#pragma once

#include <iterator>

namespace Sorts {

namespace {

template<typename Iterator>
void insertionSortImpl(Iterator begin, Iterator end) {
    Iterator j;
    typename Iterator::value_type tmp;
    for (auto i = std::next(begin); i <= end; i++) {
        tmp = *i;
        for (j = std::prev(i); j >= begin && tmp < *j; j--) {
            *(j + 1) = *j;
        }
        *(j + 1) = tmp;
    }
}

}

template <typename Iterator>
void insertionSortRange(Iterator begin, Iterator end) {
    if (begin >= end) {
        return;
    }
    insertionSortImpl(begin, std::prev(end));
}

template <typename Container>
void insertionSort(Container& array) {
    insertionSortRange(std::begin(array), std::end(array));
}

}
