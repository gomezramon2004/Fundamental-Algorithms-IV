#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

class Graph {
    private:
        void addEdge(int u, int v, std::list<int>* &adj_list);
        bool IsFalse(int i);
    public:
        void loadGraph(int n, int m, std::list<int>* &adj_list);
        void BFS(int start, int MNP, std::list<int>* &adj_list);
};