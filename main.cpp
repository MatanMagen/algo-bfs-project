#include <iostream>
#include "Graph.h"

int main() {
    int V;
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