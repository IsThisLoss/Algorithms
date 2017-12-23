//
// Created by Dima on 23.03.2017.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H

namespace details {

    template <class ContainerType, class SizeType = typename ContainerType::size_type>
    static void merge(ContainerType& array, SizeType left, SizeType right,
                      SizeType end, ContainerType& buff) {
        SizeType i, il = left, ir = right;
        for (i = left; i < end; i++)
            if (il < right && (ir >= end || array[il] <= array[ir]))
                buff[i] = array[il++];
            else
                buff[i] = array[ir++];
    }

    template <class ContainerType, class SizeType = typename ContainerType::size_type>
    static void mergeSortBackend(ContainerType& a, ContainerType& b) {
        SizeType size = a.size();
        for (SizeType width = 1; width < size; width *=2) {
            for (SizeType i = 0; i < size; i += 2*width)
                merge(a, i, std::min(i+width, size), std::min(i+2*width, size), b);
            a.swap(b);
        }
    }
}

template <class ContainerType>
void mergeSort(ContainerType& array) {
    ContainerType buf(array.size());
    details::mergeSortBackend(array, buf);
}

#endif //ALGORITHM_MERGESORT_H
