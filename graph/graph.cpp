#include "graph.hpp"

Graph::Graph() {
    this->nodes = std::vector<int>(0, 0);
    this->adj_list = new std::list<int>[0];
}

Graph::Graph(int n, std::string filename) {
    this->nodes = std::vector<int>(n, 0);
    // this->adj_list = getAdjacencyList(filename);
}

// Add an edge to the graph. Remember, this is a non-directed graph, so U <-> V
void Graph::addEdge(int u, int v, std::list<int>* &adj_list) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

// Check if the node is false
bool isFalse(int i) { return i == true; }

// Constructor of graph
void Graph::loadGraph(int n, int m, std::list<int>* &adj_list) {
    int u, v;
    adj_list =  new std::list<int>[n];

     std::vector<bool> visited(n, false); //where n is number of nodes

    for (size_t i = 0; i < m; ++i) {
        std::cout << "Introduce the edge " << i + 1 << ": "; //edges = arcs
        std::cin >> u >> v;
        addEdge(u, v, adj_list);
        visited[u] = true;
        visited[v] = true;
        if (visited[u]) {
            nodes.push_back(u);
        }
        if (visited[v]) {
            nodes.push_back(v);
        }
    }

    this->adj_list = adj_list; //quieres esto ramon???

}

void Graph::insertAdjacency(int node, int adjacency) {
    adj_list[node].push_back(adjacency); 
}

void Graph::printAdjacencyList() {
    for (int i = 0; i <= nodes.size()-1; i++) {
        std::cout << i << " -> ";
        for (auto it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Graph::printNodes() { 
    for (size_t i = 0; i < nodes.size(); ++i) {
        std::cout << nodes[i] << " ";
    }
    std::cout << std::endl;
}

// std::list<int>* Graph::getAdjacencyList(std::string filename) {
    


// }

// Breadth First Search
void Graph::BFS(int currentNode, int MNP, std::list<int>* &adj_list) {
    std::vector<bool> visited(adj_list->size(), false);
    std::queue<int> q;
    int portAccessed = currentNode;
    int count = 0;

    visited[currentNode] = true;
    q.push(currentNode);
    std::list<int>::iterator i;

    while (!q.empty() && MNP >= 0) {
        currentNode = q.front();
        std::cout << currentNode << " ";
        q.pop();

        for (i = adj_list[currentNode].begin(); i != adj_list[currentNode].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

    for (size_t i = 0; i < visited.size(); ++i) {
        if (visited[i] == false) {
            count++;
        }
    }

    std::cout << std::endl << count << "ports not reachable from port" << this->ports[portAccessed] << "with MNP: " << MNP << std::endl;

}

Graph::~Graph() {
    delete[] adj_list;
}