#pragma once

#include <iterator>

namespace BinarySearch {

template <class Container>
typename Container::const_iterator BinarySearch(const Container& array, const typename Container::value_type& value) {
    auto lo = array.begin();
    auto hi = array.end();
    if (lo == hi) {
      return hi;
    }
    while (lo < hi) {
        auto mid = std::next(lo, std::distance(lo, hi) / 2);
        if (*mid == value) {
            return mid;
        }
        if (value < *mid) {
            hi = mid;
        } else {
          lo = std::next(mid, 1);
        }
    }
    return *lo == value ? lo : array.end();
}

}
