#include "graph.hpp"

// Depth-First Search utility function for traversal
void Graph::DFSUtil(const std::string& vertex, std::unordered_set<std::string>& visited, int movesLeft) {
    // Base case: If no more moves left, stop the traversal
    if (movesLeft < 0) {
        return;
    }

    // Mark the current vertex as visited
    visited.insert(vertex);

    // Recursively visit neighbors of the current vertex
    for (const std::string& neighbor : adjacencyList[vertex]) {
        // If the neighbor has not been visited, recursively visit it with reduced moves left
        if (visited.find(neighbor) == visited.end()) {
            DFSUtil(neighbor, visited, movesLeft - 1);
        }
    }
}

// Add an edge between two vertices in the graph
void Graph::addEdge(const std::string& vertex1, const std::string& vertex2) {
    adjacencyList[vertex1].push_back(vertex2);
    adjacencyList[vertex2].push_back(vertex1); // Undirected graph: add edge in both directions
}

// Print the adjacency list representation of the graph
void Graph::printGraph() {
    for (const auto& pair : adjacencyList) {
        std::cout << pair.first << " -> ";
        for (const std::string& connectedVertex : pair.second) {
            std::cout << connectedVertex << " ";
        }
        std::cout << std::endl;
    }
}

// Count the number of unreachable ports from a starting port within a specified number of moves
int Graph::unreachableCount(const std::string& startVertex, int maxMoves) {
    std::unordered_set<std::string> visited;
    DFSUtil(startVertex, visited, maxMoves);
    return adjacencyList.size() - visited.size();
}

// Load graph data from a file and perform queries on unreachable ports
void Graph::loadFromFile(Graph& graph, const std::string& txtfile) {
    std::ifstream file(txtfile);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "File is empty" << std::endl;
        return;
    }

    int edges;
    try {
        file >> edges; // Read the number of edges
    }
    catch (std::exception& e) {
        std::cout << "Invalid data type for number of edges" << std::endl;
        return;
    }

    if (edges <= 0) {
        std::cout << "Invalid number of edges" << std::endl;
        return;
    }

    std::string vertex1, vertex2;
    std::getline(file, vertex1); // Read the rest of the first line

    // Read edge data and add edges to the graph
    for (int i = 0; i < edges; ++i) {
        file >> vertex1 >> vertex2;
        try {
            if (std::all_of(vertex1.begin(), vertex1.end(), ::isdigit) || std::all_of(vertex2.begin(), vertex2.end(), ::isdigit)) throw std::invalid_argument("Invalid data type for edge data");
            // If both vertex1 and vertex2 are not numbers, add edges to the graph
            graph.addEdge(vertex1, vertex2);
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }

    int queries;
    if (!(file >> queries)) { // Read the number of queries
        std::cout << "Invalid data type for number of queries" << std::endl; //if there is unpexpected data type where queries are called
        return;
    }

    if (queries <= 0) {
        std::cout << "Invalid number of queries" << std::endl;
        return;
    }

    // Read and process queries only if the expected number is valid
    for (int i = 0; i < queries; ++i) {
        std::string startVertex;
        int maxMoves;

        file >> startVertex >> maxMoves;
        try {
            if (std::all_of(startVertex.begin(), startVertex.end(), ::isdigit)) std::cout << "Invalid data type for starting vertex" << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            return;
        }
        if (!maxMoves) {
            std::cout << "Invalid data type for maximum number of moves" << std::endl;
            return;
        }

        int unreachable = graph.unreachableCount(startVertex, maxMoves);
        std::cout << "Case " << i + 1 << ": " << unreachable << " ports not reachable from port " << startVertex << " with MNP = " << maxMoves << "." << std::endl;
    }
}
