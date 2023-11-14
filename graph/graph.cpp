#include "graph.hpp"

// Add an edge to the graph. Remember, this is a non-directed graph, so U <-> V
void Graph::addEdge(int u, int v, std::vector<std::vector<bool>>& adj_matrix, std::list<int>* &adj_list) {
    adj_matrix[u][v] = true;
    adj_matrix[v][u] = true;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

// Deep First Search - Recursive Function
void Graph::recursiveDFS(int currentNode, std::vector<bool>& visited, std::vector<std::vector<bool>>& adj_matrix) {
    visited[currentNode] = true;
    std::cout << currentNode << " ";

    for (size_t i = 0; i < adj_matrix.size(); ++i) {
        if (adj_matrix[currentNode][i] && !visited[i]) {
            recursiveDFS(i, visited, adj_matrix);
        }
    }
}

// Constructor of graph
void Graph::loadGraph(int n, int m, std::vector<std::vector<bool>>& adj_matrix, std::list<int>* &adj_list) {
    int u, v;
    adj_matrix.assign(n, std::vector<bool>(n, false));
    adj_list =  new std::list<int>[n];

    for (size_t i = 0; i < m; ++i) {
        std::cout << "Introduce the edge " << i + 1 << ": ";
        std::cin >> u >> v;
        addEdge(u, v, adj_matrix, adj_list);
    }
}

// Deep First Search - Base Function
void Graph::DFS(int start, std::vector<std::vector<bool>>& adj_matrix) {
    std::vector<bool> visited(adj_matrix.size(), false);
    recursiveDFS(start, visited, adj_matrix);
    std::cout << std::endl;
}

// Breadth First Search
void Graph::BFS(int currentNode, std::list<int>* &adj_list) {
    std::vector<bool> visited(adj_list->size(), false);
    std::queue<int> q;

    visited[currentNode] = true;
    q.push(currentNode);
    std::list<int>::iterator i;

    while (!q.empty()) {
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

    std::cout << std::endl;
}