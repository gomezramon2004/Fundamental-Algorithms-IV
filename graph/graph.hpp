// Purpose: Header file for Graph class.
#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cctype>
#include <algorithm>

class Graph {
private:
    std::map<std::string, std::vector<std::string>> adjacencyList;

    // Utility function for Depth-First Search traversal
    void DFSUtil(const std::string& vertex, std::unordered_set<std::string>& visited, int movesLeft);

public:
    // Add an edge between two vertices in the graph
    void addEdge(const std::string& vertex1, const std::string& vertex2);

    // Print the adjacency list representation of the graph
    void printGraph();

    // Count the number of unreachable ports from a starting port within a specified number of moves
    int unreachableCount(const std::string& startVertex, int maxMoves);

    // Load graph data from a file and perform queries on unreachable ports
    void loadFromFile(Graph& graph, const std::string& txtfile);
};


