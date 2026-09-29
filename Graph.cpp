#include "Graph.h"
#include <iostream>
#include <queue>
#include <unordered_map>
void Graph::buildFromDLL(DoublyLinkedList<int>& list) {
  adjList.clear();
  Node<int>* current = list.getHead();
  while (current && current->next){
    int u = current->data;
    int v = current->next->data;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    current = current->next;
  }
}
void Graph::printAdjacency() {
  std::cout << "\nGraph adjacency list:\n";
  for (auto& pair : adjList) {
  std::cout << pair.first << ": ";
  for (int v : pair.second) std::cout << v << " ";
  std::cout << "\n";
  }
}
void Graph::BFS(int start) {
  std::unordered_map<int, bool> visited;
  std::queue<int> q;
  visited[start] = true;
  q.push(start);
  std::cout << "\nBFS traversal starting from " << start << ": ";
  while(!q.empty()) {
    int u = q.front(); q.pop();
    std::cout << u << " ";
    for (int v : adjList[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
  std::cout << std::endl;
}