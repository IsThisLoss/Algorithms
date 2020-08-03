//
// Created by Dima on 23.03.2017.
//

#pragma once

#include <cstdlib>
#include <ctime>
#include <iterator>

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end) {
    Iterator j;
    typename Iterator::value_type tmp;
    for (auto i = std::next(begin); i <= end; i++) {
        tmp = *i;
        for (j = std::prev(i); j >= begin && tmp < *j; j--) {
            *(j + 1) = *j;
        }
        *(j+1) = tmp;
    }
}

template <typename Iterator>
static void quickSortBackend(Iterator begin, Iterator end, size_t minDepth) {
    while (begin < end) {
        // small range will be sorted via insertion sort
        if (std::distance(begin, end) < minDepth) {
            insertionSort(begin, end);
            return;
        }

        // Quick Sort
        Iterator i = begin, j = end;
        // typename Iterator::value_type pivot = *(i + (rand() % std::distance(i, j))), tmp;
        typename Iterator::value_type pivot = *(i + std::distance(i, j)/2), tmp;

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

template <typename Iterator>
static void threeWayQuickSortBackend(Iterator begin, Iterator end, size_t minDepth) {
    while (begin < end) {
        // sort small range via insertion sort
        if (std::distance(begin, end) < minDepth) {
            insertionSort(begin, end);
            return;
        }

        // Quick Sort
        Iterator i = begin, j = begin, n = end;
        // typename Iterator::value_type pivot = *(i + (rand() % std::distance(i, n))), tmp;
        typename Iterator::value_type pivot = *(i + std::distance(i, n)/2);

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
        if (std::distance(begin, i-1) < std::distance(n+1, end)) {
            threeWayQuickSortBackend(begin, i - 1, minDepth);
            begin = n+1;
        } else {
            threeWayQuickSortBackend(n + 1, end, minDepth);
            end = i-1;
        }
    }
}

template <typename Iterator>
void quickSort(Iterator begin, Iterator end, size_t minDepth = 20) {
    if (begin >= end) {
        return;
    }
    //srand(time(nullptr));
    quickSortBackend(begin, end - 1, minDepth);
}

template <typename Iterator>
void threeWayQuickSort(Iterator begin, Iterator end, size_t minDepth = 20) {
    if (begin >= end) {
        return;
    }
    //srand(time(nullptr));
    threeWayQuickSortBackend(begin, end - 1, minDepth);
}
