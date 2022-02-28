#pragma once

#include <vector>

namespace DataStructures {

template <typename Key>
class PriorityQueue {
private:
    std::vector<Key> v;

    void siftUp(int i) {
        int parent;
        while (i > 0) {
            parent = (i - 1) / 2;
            if (v[i] <= v[parent])
                return;
            std::swap(v[i], v[parent]);
            i = parent;
        }
    }

    void siftDown(int i) {
        int left = 2*i+1, right = 2*i+2, largest = i;

        if (left < v.size() && v[left] > v[i])
            largest = left;

        if (right < v.size() && v[right] > v[largest])
            largest = right;

        if(largest != i) {
            std::swap(v[largest], v[i]);
            siftDown(largest);
        }
    }

public:
    void insert(const Key& x) {
        v.push_back(x);
        siftUp(v.size() - 1);
    }

    Key top() const {
        return v.front();
    }

    Key pop() {
        Key res = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();

        if (!v.empty())
            siftDown(0);

        return res;
    }

    bool isEmpty() const {
        return v.empty();
    }

};

}
