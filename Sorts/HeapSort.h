//
// Created by isthisloss on 23.03.2017.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

#include <algorithm>

template <typename Container_t>
static void heapify(Container_t& array, int size, int i) {
    int left = 2*i+1, right = 2*i+2, largest = i;
    if (left < size && array[i] < array[left])
        largest = left;
    if (right < size && array[largest] < array[right])
        largest = right;
    if (largest != i) {
        std::swap(array[largest], array[i]);
        heapify(array, size, largest);
    }
}

template <typename Container_t>
static void makeHeap(Container_t& array, int heapSize) {
    for (int i = heapSize / 2; i >= 0; i--)
        heapify(array, heapSize, i);
}

template <typename Container_t>
void heapSort(Container_t& array) {
    int heapSize = array.size();
    makeHeap(array, heapSize);
    while (heapSize > 1) {
        std::swap(array[0], array[heapSize-1]);
        heapSize--;
        heapify(array, heapSize, 0);
    }
}

#endif //ALGORITHM_HEAPSORT_H
