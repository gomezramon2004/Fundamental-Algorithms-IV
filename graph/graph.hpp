#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

class Graph {
    private:
        void addEdge(int u, int v, std::vector<std::vector<bool>>& adj_matrix, std::list<int>* &adj_list);
        void recursiveDFS(int currentNode, std::vector<bool>& visited, std::vector<std::vector<bool>>& adj_matrix);
    public:
        void loadGraph(int n, int m, std::vector<std::vector<bool>>& adj_matrix, std::list<int>* &adj_list);
        void DFS(int start, std::vector<std::vector<bool>>& adj_matrix);
        void BFS(int start,  std::list<int>* &adj_list);
};