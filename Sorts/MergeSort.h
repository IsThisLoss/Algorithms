#pragma once

#include <algorithm>
#include <iostream>

namespace Sorts {

namespace details {

template <class ContainerType, class SizeType = typename ContainerType::size_type>
void iterativeMerge(ContainerType& array, SizeType left, SizeType right,
                  SizeType end, ContainerType& buff) {
    SizeType i, il = left, ir = right;
    for (i = left; i < end; i++) {
        if (il < right && (ir >= end || array[il] <= array[ir])) {
            buff[i] = array[il++];
        } else {
            buff[i] = array[ir++];
        }
    }
}

template <class ContainerType, class SizeType = typename ContainerType::size_type>
static void mergeSortBackend(ContainerType& a, ContainerType& b) {
    SizeType size = a.size();
    for (SizeType width = 1; width < size; width *=2) {
        for (SizeType i = 0; i < size; i += 2 * width) {
            iterativeMerge(a, i, std::min(i + width, size), std::min(i + 2 * width, size), b);
        }
        a.swap(b);
    }
}

template <class Iterator>
void print(Iterator begin, Iterator end) {
    for (; begin < end; begin++) {
        std::cerr << *begin << ' ';
    }
    std::cerr << std::endl;
}

template <class Container>
void merge(Container& array, size_t begin, size_t mid, size_t end, Container& buf) {
    buf.clear();
    size_t i = begin;
    size_t j = mid;
    while (i < mid && j < end) {
        if (array[i] <= array[j]) {
            buf.push_back(array[i++]);
        } else {
            buf.push_back(array[j++]);
        }
    }
    while (i < mid) {
        buf.push_back(array[i++]);
    }
    while (j < end) {
        buf.push_back(array[j++]);
    }
    std::copy(buf.begin(), buf.end(), std::next(array.begin(), begin));
}

template <class Container>
void recursiveMergeSortBackend(Container& array, size_t begin, size_t end, Container& buf) {
    if (end - begin <= 1) {
        return;
    }
    auto mid = begin + (end - begin) / 2;
    recursiveMergeSortBackend(array, begin, mid, buf);
    recursiveMergeSortBackend(array, mid, end, buf);
    merge(array, begin, mid, end, buf);
}

}

template <class Container>
void mergeSort(Container& array) {
    Container buf(array.size());
    details::mergeSortBackend(array, buf);
}

template <class Container>
void recursiveMergeSort(Container& array) {
    Container buf(array.size());
    details::recursiveMergeSortBackend(array, 0, array.size(), buf);
}

}
