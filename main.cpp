#include <iostream>
#include "Graph.h"

int main() {
    int V, E;
    std::cout << "Enter number of vertices: ";
    std::cin >> V;

    Graph g(V);

    std::cout << "Enter number of edges: ";
    std::cin >> E;

    std::cout << "Enter the edges (as pairs of vertices):" << std::endl;
    for (int i = 0; i < E; ++i) {
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