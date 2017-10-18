#include <iostream>
#include <vector>
#include "Sorts/QuickSort.h"

int main() {
    std::vector<int> v = {8, 9, 11, 3, 4, 9, 8, 7};
    quickSort(v.begin(), v.end());
    for (auto& i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}