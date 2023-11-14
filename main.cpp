#include "./graph/graph.cpp" //////////////////RECORDATORIO AL RAMON LE CORRE DIF   /////////////////                   

// In this program it will be used a Graph object to load a graph using an adjacency matrix and list, based on the number of nodes and edges introduced by the input stream.
// Then, it will be used the DFS and BFS algorithms to traverse the graph, starting from a node introduced by the input stream.

int main() {
    Graph g;
    std::list<int>* adj_list;
    int n, m, start, MNP;

    std::cout << g.ports[9] << std::endl;

    std::cout << "Introduce the number of nodes: ";
    std::cin >> n;
    std::cout << "Introduce the number of edges: ";
    std::cin >> m;

    g.loadGraph(n, m, adj_list);

    std::cout << "Introduce the start node: ";
    std::cin >> start;

    std::cout << "Introduce the MNP: "; // MNP = Max Number of Paths
    std::cin >> MNP;

    std::cout << "BFS: ";
    g.BFS(start, MNP, adj_list);

    std::cout << std::endl;
    g.printAdjacencyList();

    return 0;
}