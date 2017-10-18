//
// Created by Dima on 23.03.2017.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include <cstdlib>
#include <ctime>
#include <iterator>

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
    Iterator j;
    typename Iterator::value_type tmp;
    for (auto i = begin + 1; i <= end; i++) {
        tmp = *i;
        for (j = i - 1; j >= begin && tmp < *j; j--)
            *(j+1) = *j;
        *(j+1) = tmp;
    }
}

template <typename Iterator>
static void _q_srt(Iterator begin, Iterator end, size_t min_depth)
{
    if (std::distance(begin, end) < min_depth) {
        insertionSort(begin, end);
        return;
    }

    while (begin < end) {
        Iterator i = begin, j = end;

        typename Iterator::value_type pivot = *(i + (rand() % std::distance(i, j))), tmp;

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
            _q_srt(begin, j, min_depth);
            begin = i;
        } else {
            _q_srt(i, end, min_depth);
            end = j;
        }
    }
}

template <typename Iterator>
void quickSort(Iterator begin, Iterator end, size_t min_depth = 20) {
    srand(time(nullptr));
    _q_srt(begin, end-1, min_depth);
}


#endif //ALGORITHM_QUICKSORT_H
