#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

class Graph {
    private:
        void addEdge(int u, int v, std::list<int>* &adj_list);
    public:
        void loadGraph(int n, int m, std::list<int>* &adj_list);
        void BFS(int start,  std::list<int>* &adj_list);
};