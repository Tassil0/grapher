/*****************************************************************//**
 * @file   Graph.cpp
 * @brief  Graph datastructure class
 *
 * @author SIK0207
 * @date   13.05.2023
 *********************************************************************/

#include <fstream>
#include "headers/Graph.h"

/**
 * @brief Contruct graph from file
 * @param fileName
 */
Graph::Graph(std::string &fileName) {
    this->Name = fileName;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw "File does not exist.";
    }
    // maybe faster with arrays?
    std::string line;
    int nodeKey, neighborKey;
    while (!file.eof()) {
        file >> nodeKey >> neighborKey;
        this->AddEdge(nodeKey, neighborKey);
    }
    file.close();
}

/**
 * @brief make new object from graph
 * @param rhs
 * @return graph structure
 */
Graph &Graph::operator=(const Graph &rhs) {
    for (auto node : rhs.Nodes) {
        for (auto neighborNode : node->Neighbors) {
            this->AddEdge(node->Key, neighborNode->Key);
        }
    }
    return *this;
}

/**
 * @brief does the graph contain key?
 * @param key searched key
 * @return bool
 */
bool Graph::HasKey(int key) {
    return std::any_of(this->Nodes.begin(), this->Nodes.end(), [key](auto node) { return node->Key == key;});
}

/**
 * @brief adds edge to graph
 * @param nodeKey
 * @param neighborKey
 */
void Graph::AddEdge(int nodeKey, int neighborKey) {
    auto node = this->GetNode(nodeKey);
    auto neighbor = this->GetNode(neighborKey);
    if (node == nullptr) {
        this->Nodes.push_back(new Node(nodeKey));
        node = this->Nodes.back();
    }
    if (neighbor == nullptr) {
        this->Nodes.push_back(new Node(neighborKey));
        neighbor = this->Nodes.back();
    }
    node->Neighbors.push_back(neighbor);
    neighbor->Neighbors.push_back(node);
}

/**
 * @brief queries node from graph by key
 * @param key
 * @return node
 */
Node *Graph::GetNode(int key) {
    for (auto node : this->Nodes) {
        if (node->Key == key)
            return node;
    }
    return nullptr;
}

/**
 * @brief prints the visual representation of graph
 */
void Graph::Print() {
    for (auto node : this->Nodes) {
        std::cout << "[ " << node->Key << " ]";
        for (auto neighborNode : node->Neighbors)
            std::cout << " -> " << neighborNode->Key;
        std::cout << std::endl;
    }
}
