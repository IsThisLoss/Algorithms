//
// Created by Dima on 23.03.2017.
//

#pragma once

#include "InsertionSort.h"

#include <cstdlib>
#include <ctime>
#include <iterator>
#include <functional>
#include <vector>

namespace details {
    template<typename Iterator>
    void quickSortBackend(Iterator begin, Iterator end, size_t minDepth) {
        while (begin < end) {
            // small range will be sorted via insertion sort
            if (std::distance(begin, end) < minDepth) {
                insertionSortRange(begin, end);
                return;
            }

            // Quick Sort
            Iterator i = begin, j = end;
            typename Iterator::value_type pivot = *(i + std::distance(i, j) / 2), tmp;

            // partition
            while (i <= j) {
                while (*i < pivot)
                    i++;
                while (*j > pivot)
                    j--;
                if (i <= j) {
                    tmp = *i;
                    *i = *j;
                    *j = tmp;
                    i++;
                    j--;
                }
            }

            // tail recursion optimization
            if (std::distance(begin, j) < std::distance(i, end)) {
                quickSortBackend(begin, j, minDepth);
                begin = i;
            } else {
                quickSortBackend(i, end, minDepth);
                end = j;
            }
        }
    }

    template<typename Iterator>
    void threeWayQuickSortBackend(Iterator begin, Iterator end, size_t minDepth) {
        while (begin < end) {
            // sort small range via insertion sort
            if (std::distance(begin, end) < minDepth) {
                insertionSortRange(begin, end);
                return;
            }

            // Quick Sort
            Iterator i = begin, j = begin, n = end;
            typename Iterator::value_type pivot = *(i + std::distance(i, n) / 2);

            //Three way partition
            while (j <= n) {
                if (*j < pivot) {
                    std::swap(*i, *j);
                    i++;
                    j++;
                } else if (*j > pivot) {
                    std::swap(*j, *n);
                    n--;
                } else {
                    j++;
                }
            }

            // tail recursion optimization
            if (std::distance(begin, i - 1) < std::distance(n + 1, end)) {
                threeWayQuickSortBackend(begin, i - 1, minDepth);
                begin = n + 1;
            } else {
                threeWayQuickSortBackend(n + 1, end, minDepth);
                end = i - 1;
            }
        }
    }
}

template <typename Iterator>
void quickSortRange(Iterator begin, Iterator end) {
    if (begin >= end) {
        return;
    }
    details::quickSortBackend(begin, std::prev(end), 0);
}

template <typename Container>
void quickSort(Container& array) {
    quickSortRange(std::begin(array), std::end(array));
}

template <typename Iterator>
void threeWayQuickSortRange(Iterator begin, Iterator end, size_t minDepth = 0) {
    if (begin >= end) {
        return;
    }
    details::threeWayQuickSortBackend(begin, std::prev(end), minDepth);
}

template <typename Container>
void threeWayQuickSort(Container& array) {
    threeWayQuickSortRange(std::begin(array), std::end(array));
}