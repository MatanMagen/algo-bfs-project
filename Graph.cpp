#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void BFS(int start, int end);

private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    std::vector<std::list<int>> p; // Parent array to store multiple parents
};

Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
    p.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

void Graph::BFS(int start, int end) {
    std::vector<int> d(vertices, vertices + 1); // Distance array, initialized to a large value
    std::list<int> q; // Queue for BFS

    d[start] = 0;
    q.push_back(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop_front();

        for (int neighbor : adjList[node]) {
            if (d[neighbor] == vertices + 1) { // If the neighbor hasn't been visited
                d[neighbor] = d[node] + 1;
                p[neighbor].push_back(node);
                q.push_back(neighbor);
            } else if (d[neighbor] == d[node] + 1) { // If the neighbor is part of another shortest path
                p[neighbor].push_back(node);
            }
        }
    }
}