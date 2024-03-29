#pragma once

#include <cstdint>
#include <cstring>

namespace Sorts {

constexpr const int MAX_BYTE = 256;

template <typename IntType>
unsigned char getByte(const IntType& x, const unsigned& n) {
    return (unsigned char) ((x >> (8*n)) & 0xff);
}

template <typename Int_type>
void countSort(Int_type* A, unsigned n, unsigned byte) {
    int C[MAX_BYTE];
    memset(C, 0x0, MAX_BYTE * sizeof(int));
    int64_t* B = new int64_t[n];

    for (int i = 0; i < n; i++)
        C[(int)getByte(A[i], byte)]++;

    for (int i = 1; i < MAX_BYTE; i++)
        C[i] += C[i-1];

    for (int i = n-1; i >= 0; i--)
        B[--C[(int)getByte(A[i], byte)]] = A[i];

    memcpy(A, B, n * sizeof(int64_t));
    delete [] B;
}

template <typename Int_type>
void LSDByteSort(Int_type* A, unsigned n) {
    for (unsigned i = 0; i < sizeof(Int_type); i++)
        countSort(A, n, i);
}

}
