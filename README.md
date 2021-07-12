# Algorithms
My implementation of popular algorithms 

![CI](https://github.com/IsThisLoss/Algorithms/actions/workflows/ci.yml/badge.svg)

## 1. Sorts
  * [Heap sort](https://github.com/IsThisLoss/Algorithms/blob/master/Sorts/HeapSort.h)
  * [Merge sort](https://github.com/IsThisLoss/Algorithms/blob/master/Sorts/MergeSort.h)
  * [Quick Sort (both two-way-partition and three-way-partition](https://github.com/IsThisLoss/Algorithms/blob/master/Sorts/QuickSort.h)
  
  Also there is some kind of comparison of those algorithms in file [Test.h](https://github.com/IsThisLoss/Algorithms/blob/master/Sorts/Test.h)
results are below.

```
Array size is 10000000 elements of int
Classic QuickSort took 4629 milliseconds
Three-way-partition QuickSort took 5896 milliseconds
Megre Sort took 4252 milliseconds
Heap Sort took 11820 milliseconds
```
I don't know why Heap sort is so slow, so if anyone knows, please tell me. Maybe I've made a mistake in implementation.

## 2. Graphs
  * [Defenition of Graph class](https://github.com/IsThisLoss/Algorithms/blob/master/Graphs/Graph.h)
  * [Counting the number of connected components (via Depth-first search)](https://github.com/IsThisLoss/Algorithms/blob/master/Graphs/ConnectedComponents.h)
  * [Distances from a vertex to all others](https://github.com/IsThisLoss/Algorithms/blob/master/Graphs/DistancesFromVertex.h)
  * [Topological sort](https://github.com/IsThisLoss/Algorithms/blob/master/Graphs/TopologicalSort.h)
  * [Dijkstra's algorithm](https://github.com/IsThisLoss/Algorithms/blob/master/Graphs/DijkstraSparse.h)

Also There is [Ford-Bellman algorithm](https://github.com/IsThisLoss/Algorithms/blob/master/Graphs/FordBellman.h), but I still have not tested it.

## 3. Data Structurers
  * [AVL Three](https://github.com/IsThisLoss/Algorithms/blob/master/DataStructures/AVLTree.h)
  * [Hash Table](https://github.com/IsThisLoss/Algorithms/blob/master/DataStructures/HashTable.h)
  * [Priority Queue (on Heap)](https://github.com/IsThisLoss/Algorithms/blob/master/DataStructures/PriorityQueue.h)
  * [Treap](https://github.com/IsThisLoss/Algorithms/blob/master/DataStructures/Treap.h)
  
## 4. Algorithms on strings
  * [Knuth–Morris–Pratt string searching algorithm](https://github.com/IsThisLoss/Algorithms/blob/master/StringUtils/KmpSearch.h)
  * [Split String by Separator](https://github.com/IsThisLoss/Algorithms/blob/master/StringUtils/StringSplit.h)
  
## 5. Others
  * [Base64 encoder and decoder](https://github.com/IsThisLoss/Algorithms/tree/master/Base64)
  * [Minimal String with Short String Optimization](https://github.com/IsThisLoss/Algorithms/tree/master/String)
