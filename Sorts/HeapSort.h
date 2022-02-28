#pragma once

#include <algorithm>

namespace Sorts {

template <typename Container>
static void heapify(Container& array, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < size && array[i] < array[left]) {
        largest = left;
    }
    if (right < size && array[largest] < array[right]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(array[largest], array[i]);
        heapify(array, size, largest);
    }
}

template <typename Container>
static void makeHeap(Container& array, int heapSize) {
    for (int i = heapSize / 2; i >= 0; i--) {
        heapify(array, heapSize, i);
    }
}

template <typename Container>
void heapSort(Container& array) {
    int heapSize = array.size();
    makeHeap(array, heapSize);
    while (heapSize > 1) {
        std::swap(array[0], array[heapSize-1]);
        heapSize--;
        heapify(array, heapSize, 0);
    }
}

}
