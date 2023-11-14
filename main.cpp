#include "./graph/graph.hpp"

// In this program it will be used a Graph object to load a graph using an adjacency matrix and list, based on the number of nodes and edges introduced by the input stream.
// Then, it will be used the DFS and BFS algorithms to traverse the graph, starting from a node introduced by the input stream.

int main() {
    Graph g;
    std::vector<std::vector<bool>> adj_matrix;
    std::list<int>* adj_list;
    int n, m, start;

    std::cout << "Introduce the number of nodes: ";
    std::cin >> n;
    std::cout << "Introduce the number of edges: ";
    std::cin >> m;

    g.loadGraph(n, m, adj_matrix, adj_list);

    std::cout << "Introduce the start node: ";
    std::cin >> start;

    std::cout << "DFS: ";
    g.DFS(start, adj_matrix);

    std::cout << "BFS: ";
    g.BFS(start, adj_list);

    return 0;
}