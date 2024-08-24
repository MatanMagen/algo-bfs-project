#include "Graph.h"
#include <iostream>
#include <vector>
#include <list>

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V + 1);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v); // For an undirected graph
}

void Graph::BFS(int start, int end) {
    std::vector<bool> visited(V + 1, false); // Visited vector
    std::vector<int> parent(V + 1, -1); // To store the parent of each vertex

    std::list<int> q; // Queue implemented using list
    q.push_back(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop_front();

        // If we reached the end, break
        if (node == end) break;

        // Explore neighbors
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push_back(neighbor);
            }
        }
    }

    // Reconstruct the path
    std::list<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_front(v);
    }

    // Output the result
    if (path.front() == start) {
        std::cout << "Shortest path from " << start << " to " << end << " is: ";
        for (int v : path) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
        std::cout << "Distance is: " << path.size() - 1 << std::endl;
    } else {
        std::cout << "No path exists between " << start << " and " << end << std::endl;
    }
}