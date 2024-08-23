#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

class Graph {
    int V; // Number of vertices
    std::unordered_map<int, std::list<int>> adjList; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
    }

    // Add an edge to the graph
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // For an undirected graph
    }

    // BFS to find the shortest path from source to destination
    void BFS(int start, int end) {
        std::vector<bool> visited(V + 1, false); // Visited vector
        std::vector<int> parent(V + 1, -1); // To store the parent of each vertex

        std::queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // If we reached the end, break
            if (node == end) break;

            // Explore neighbors
            for (auto neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        // Reconstruct the path
        std::vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        std::reverse(path.begin(), path.end());

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
};

int main() {
    int V, E;
    std::cout << "Enter number of vertices: ";
    std::cin >> V;

    Graph g(V);

    std::cout << "Enter the edges (as pairs of vertices):" << std::endl;
    for (int i = 0; i < V - 1; ++i) {
        int v, w;
        std::cin >> v >> w;
        g.addEdge(v, w);
    }

    int start, end;
    std::cout << "Enter the start and end vertices: ";
    std::cin >> start >> end;

    g.BFS(start, end);

    return 0;
}
