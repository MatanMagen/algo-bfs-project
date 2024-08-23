#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <list>
#include <vector>

class Graph {
    int V; // Number of vertices
    std::unordered_map<int, std::list<int>> adjList; // Adjacency list

public:
    // Constructor
    Graph(int V);

    // Add an edge to the graph
    void addEdge(int v, int w);

    // BFS to find the shortest path from source to destination
    void BFS(int start, int end);
};

#endif // GRAPH_H