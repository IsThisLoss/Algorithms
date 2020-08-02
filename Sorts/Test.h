//
// Created by Dima on 22.10.2017.
//

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "./QuickSort.h"
#include "./MergeSort.h"
#include "./HeapSort.h"

void sortTest() {
    // init
    constexpr unsigned N = 10000000;
    std::cout << "Array size is " << N << " elements of int\n";
    std::vector<int> quickSortArray(N);
    srand(static_cast<unsigned>(time(nullptr)));
    std::generate(quickSortArray.begin(), quickSortArray.end(), rand);
    auto threeWayQuickSortArray = quickSortArray;
    auto mergeSortArray = quickSortArray;
    auto heapSortArray = quickSortArray;

    // classic QuickSort
    auto t1 = std::chrono::high_resolution_clock::now();
    quickSort(quickSortArray.begin(), quickSortArray.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Classic QuickSort took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    // three-way-partition QuickSort
    t1 = std::chrono::high_resolution_clock::now();
    threeWayQuickSort(threeWayQuickSortArray.begin(), threeWayQuickSortArray.end());
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Three-way-partition QuickSort took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    // Megre Sort
    t1 = std::chrono::high_resolution_clock::now();
    mergeSort(mergeSortArray);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Megre Sort took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    // Heap Sort
    t1 = std::chrono::high_resolution_clock::now();
    heapSort(heapSortArray);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Heap Sort took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
}
