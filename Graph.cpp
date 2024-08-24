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
};

Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

void Graph::BFS(int start, int end) {
    std::vector<int> d(vertices, vertices + 1); // Distance array, initialized to a large value
    std::vector<int> p(vertices, -1); // Parent array
    std::list<int> q; // Queue for BFS

    d[start] = 0;
    q.push_back(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop_front();

        for (int neighbor : adjList[node]) {
            if (d[neighbor] == vertices + 1) { // If the neighbor hasn't been visited
                d[neighbor] = d[node] + 1;
                p[neighbor] = node;
                q.push_back(neighbor);
            }
        }
    }

    if (p[end] == -1) {
        std::cout << "No path from " << start << " to " << end << std::endl;
    } else {
        std::cout << "Shortest path from " << start << " to " << end << ": ";
        for (int at = end; at != -1; at = p[at]) {
            std::cout << at << " ";
        }
        std::cout << std::endl;
    }




}