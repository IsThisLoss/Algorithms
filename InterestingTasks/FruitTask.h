//
// Created by Dima on 23.03.2017.
//

#ifndef ALGORITHM_FRUITTASK_H
#define ALGORITHM_FRUITTASK_H


#include <iostream>
#include "../DataStructures/PriorityQueue.h"

// TODO

int fuitTask()
{
    int n, x, k, top, sum;
    std::cin >> n;

    PriorityQueue<int> pq;

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        pq.insert(x);
    }

    std::cin >> k;

    x = sum = 0;
    std::deque<int> got;
    while (!pq.isEmpty())
    {
        sum = pq.pop();
        got.push_back(sum);
        while (sum <= k && !pq.isEmpty())
        {
            sum += pq.top();
            got.push_back(pq.pop());
        }

        if (sum > k)
        {
            pq.insert(got.back());
            got.pop_back();
        }

        for (auto& i : got)
            if (i != 1)
                pq.insert(i/2);

        got.clear();
        x++;
    }

    return x;
}

#endif //ALGORITHM_FRUITTASK_H
