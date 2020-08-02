//
// Created by Dima on 20.03.2017.
//

#include "arrays.h"

#include <cmath>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <stack>

void fill(int* A, int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
}

int binSearch(int* A, int size, int find) {
    int first = 0, last = size, mid = 0;
    while (first < last) {
        mid = (first + last) / 2;
        if (find <= A[mid]) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }
    if (first == size || A[first] != find) {
        return -1;
    }
    return first;
}

int closestInSortedArray(int A[], int size, int find) {
    int first = 0, last = size, mid = 0;
    while (first < last) {
        mid = (first + last) / 2;
        if (find <= A[mid]) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }

    if (first == size) {
        return size - 1;
    }
    if (first > 0 && std::abs(A[first-1] - find) <=  std::abs(A[first] - find)) {
        return first - 1;
    }
    return first;
}

std::string bracketsBalansing(const std::string& string) {
    std::deque<char> d;
    std::stack<char> s;
    std::unordered_map<char, char> pairs = {
            {'{', '}'},
            {'}', '{'},
            {'[', ']'},
            {']', '['},
            {'(', ')'},
            {')', '('}
    };

    std::unordered_set<char> opening = {'(', '[', '{'};
    std::unordered_set<char> closing = {')', ']', '}'};

    for (const char& i : string) {
        d.push_back(i);
    }

    auto end = d.end();
    for (auto i = d.begin(); i != end; i++) {
        if (opening.find(*i) != opening.end()) {
            s.push(pairs[*i]);
        } else if (closing.find(*i) != closing.end()) {
            if (s.empty()) {
                d.push_front(pairs[*i]);
            } else if (s.top() == *i) {
                s.pop();
            } else {
                return "IMPOSSIBLE";
            }
        }
    }

    while (!s.empty()) {
        auto var = s.top();
        d.push_back(var);
        s.pop();
    }

    std::string result;
    result.reserve(d.size());
    for (auto& i : d) {
        result.push_back(i);
    }
    return result;
}
