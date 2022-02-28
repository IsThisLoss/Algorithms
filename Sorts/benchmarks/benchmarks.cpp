#include <benchmark/benchmark.h>

#include "QuickSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"

#include <cstdlib>
#include <ctime>

namespace Sorts {

namespace {

std::vector<int> GenerateInput() {
    constexpr unsigned N = 100000;
    std::vector<int> array(N);
    srand(static_cast<unsigned>(time(nullptr)));
    std::generate(array.begin(), array.end(), rand);
    return array;
}

const std::vector<int> stableInput = GenerateInput();

std::vector<int> GetStableInput() {
    return stableInput;
}

}

void BM_quickSort(benchmark::State& state) {
    for (auto _ : state) {
        auto input = GetStableInput();
        quickSort(input);
    }
}

BENCHMARK(BM_quickSort);

void BM_mergeSort(benchmark::State& state) {
    for (auto _ : state) {
        auto input = GetStableInput();
        mergeSort(input);
    }
}

BENCHMARK(BM_mergeSort);

void BM_recursiveMergeSort(benchmark::State& state) {
    for (auto _ : state) {
        auto input = GetStableInput();
        recursiveMergeSort(input);
    }
}

BENCHMARK(BM_recursiveMergeSort);

void BM_insertionSort(benchmark::State& state) {
    for (auto _ : state) {
        auto input = GetStableInput();
        insertionSort(input);
    }
}

BENCHMARK(BM_insertionSort);

void BM_heapSort(benchmark::State& state) {
    for (auto _ : state) {
        auto input = GetStableInput();
        heapSort(input);
    }
}

BENCHMARK(BM_heapSort);

}

BENCHMARK_MAIN();
