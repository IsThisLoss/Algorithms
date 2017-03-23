//
// Created by Dima on 21.03.2017.
//

#ifndef ALGORITHM_PRIORITYQUEUE_H
#define ALGORITHM_PRIORITYQUEUE_H

#include <vector>
#include <deque>
#include <iostream>

template <typename T>
class PriorityQueue
{
private:
    std::vector<T> v;

    void siftUp(int i)
    {
        int parent;
        while (i > 0)
        {
            parent = (i - 1) / 2;
            if (v[i] <= v[parent])
                return;
            std::swap(v[i], v[parent]);
            i = parent;
        }
    }

    void siftDown(int i)
    {
        int left = 2*i+1, right = 2*i+2, largest = i;
        if (left < v.size() && v[left] > v[i])
            largest = left;
        if (right < v.size() && v[right] > v[largest])
            largest = right;
        if(largest != i)
        {
            std::swap(v[largest], v[i]);
            siftDown(largest);
        }
    }

public:
    void insert(T x)
    {
        v.push_back(x);
        siftUp(v.size() - 1);
    }

    int top() const
    {
        return v[0];
    }

    int pop()
    {
        int res = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();

        if (!v.empty())
            siftDown(0);

        return res;
    }

    bool isEmpty() const
    {
        return v.empty();
    }

};

#endif //ALGORITHM_PRIORITYQUEUE_H
