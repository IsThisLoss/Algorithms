//
// Created by Dima on 23.03.2017.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H

// @todo separate from class to functions
template <class Container_t>
class MergeSorter {
private:
    using index_t = typename Container_t::size_type;

    static inline index_t min(index_t a, index_t b) {
        return a < b ? a : b;
    }

    static void merge(Container_t& array, index_t left, index_t right,
                      index_t end, Container_t& buff) {

        index_t i, il = left, ir = right;
        for (i = left; i < end; i++)
            if (il < right && (ir >= end || array[il] <= array[ir]))
                buff[i] = array[il++];
            else
                buff[i] = array[ir++];
    }

    static void _mergeSort(Container_t& a, Container_t& b) {
        index_t size = a.size();

        for (index_t width = 1; width < size; width *=2) {
            for (index_t i = 0; i < size; i += 2*width)
                merge(a, i, min(i+width, size), min(i+2*width, size), b);
            a.swap(b);
        }
    }

public:
    MergeSorter() = delete;
    static void mergeSort(Container_t& array) {
        Container_t buff(array.size());
        _mergeSort(array, buff);
    }
};


#endif //ALGORITHM_MERGESORT_H
