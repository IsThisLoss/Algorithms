//
// Created by Dima on 17.03.2017.
//

#ifndef SORTING_MERGE_SORT_H
#define SORTING_MERGE_SORT_H

#include <algorithm>
#include <iostream>
#include <vector>

// TODO

struct Point
{
    int x;
    bool isBegin;

    Point(int x = 0, bool isBeing = true)
    {
        this->x = x;
        this->isBegin = isBeing;
    }

    bool operator<=(Point that)
    {
        return x <= that.x;
    }
};

// it's not so bad if I will keep this in .h file :)
int LinesTask(std::deque<int> input)
{
    std::vector<Point> v;
    while (!input.empty())
    {
        x1 = input.front();
        input.pop_front();
        x2 = input.front();
        input.pop_front();

        v.push_back(Point(x1, true));
        v.push_back(Point(x2, false));
    }

    MergeSorter<std::vector<Point>> m;
    m.mergeSort(v);

    int len = 0, count = 0, beginning = -1;
    for (auto& i : v)
    {
        if (i.isBegin)
        {
            count++;
            if (count == 1)
                beginning = i.x;
            else if (count == 2)
                len += i.x - beginning;
        }
        else
        {
            count--;
            if (count == 0)
                len += i.x - beginning;
            else if (count == 1)
                beginning = i.x;
        }
    }
    return len;
}

#endif //SORTING_MERGE_SORT_H
