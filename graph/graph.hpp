#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>

class Graph {
    std::vector<int> nodes;
    std::list<int>* adj_list;
    private:
        void addEdge(int u, int v, std::list<int>* &adj_list);
        bool IsFalse(int i);
    public:
        Graph();
        Graph(int n, int m, std::string filename);
        ~Graph();

        std::string ports[13] = {"Alexandria", "Algeciras", "Ambarli", "Antwerp", "Balboa", "Bandar", "Barcelona", "Bremen", "Busan", "Cai_Mep", "Callao", "Cartagena", "Charleston"};

        void loadGraph(int n, int m, std::list<int>* &adj_list);
        void BFS(int start, int MNP, std::list<int>* &adj_list);
        void insertAdjacency(int node, int adjacency);
        std::list<int>* getAdjacencyList(int m, std::string filename);
        void printAdjacencyList();
        void printNodes(); //debug purposes
};

