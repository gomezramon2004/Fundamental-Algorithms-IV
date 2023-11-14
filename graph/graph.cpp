#include "graph.hpp"

Graph::Graph() {
    this->nodes = std::vector<int>(0, 0);
    this->adj_list = new std::list<int>[0];
}

Graph::Graph(int n, int m, std::string filename) {
    this->nodes = std::vector<int>(n, 0);
    this->adj_list = getAdjacencyList(m, filename); //puedo implemantar el usar load graph en este constructor
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

    this->adj_list = adj_list; 

}

void Graph::insertAdjacency(int node, int adjacency) {
    adj_list[node].push_back(adjacency); 
}

void Graph::printAdjacencyList() { ///formatear para que se entienda mejor, imprime cada una de las adjs enumeradas
    for (int i = 0; i < 16; i++) {  
        std::cout << i + 1 << " -> ";
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


std::list<int>* Graph::getAdjacencyList(int m, std::string txtfile) {
    std::ifstream file;
    file.open(txtfile);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return nullptr;
    }

    std::list<int>* file_list = new std::list<int>[m]; 

    std::string line;
    int i = 0;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        while (getline(ss, token, ' ')) {
            file_list[i].push_back(stoi(token));
        }
        ++i;
    }

    return file_list; 
}

// Breadth First Search
void Graph::BFS(int currentNode, int MNP, std::list<int>* &adj_list) { ///hacer el cambio por uso de el atributo adj_list
    std::vector<bool> visited(this->adj_list->size(), false);
    std::queue<int> q;
    int portAccessed = currentNode;
    int count = 0;

    visited[currentNode] = true;
    q.push(currentNode);
    std::list<int>::iterator i;

    std::list<int> unreachableNodes;

    while (!q.empty() && MNP >= 0) {
        currentNode = q.front();
        std::cout << currentNode << " ";
        q.pop();

        for (i = this->adj_list[currentNode].begin(); i != this->adj_list[currentNode].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

    for (size_t i = 0; i < this->adj_list->size(); ++i) {
        if (!visited[i]) {
            count++;
            unreachableNodes.push_back(i);
        }
    }


    std::cout << std::endl << count << " ports not reachable from port " << this->ports[portAccessed] << " with MNP: " << MNP << std::endl;

}

Graph::~Graph() {
    delete[] adj_list;
}