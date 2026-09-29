#ifndef GRAPH_H
#define GRAPH_H

#include "DoublyLinkedList.h"
#include <unordered_map>
#include <vector>

class Graph {
private:
    std::unordered_map<int, std::vector<int>> adjList;

public:
    void buildFromDLL(DoublyLinkedList<int>& list);
    void printAdjacency();
    void BFS(int start);
};

#endif
