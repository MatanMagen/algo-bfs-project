#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

class Graph {
    int V; // Number of vertices
    std::vector<std::list<int>> adjList; // Adjacency list

public:
    // Constructor
    Graph(int V);

    // Add an edge to the graph
    void addEdge(int v, int w);

    // BFS to find the shortest path from source to destination
    void BFS(int start, int end);
};

#endif // GRAPH_H