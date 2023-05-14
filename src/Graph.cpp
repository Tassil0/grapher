/*****************************************************************//**
 * \file   Graph.cpp
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#include <fstream>
#include "headers/Graph.h"

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

Graph &Graph::operator=(const Graph &rhs) {
    for (auto node : rhs.Nodes) {
        for (auto neighborNode : node->Neighbors) {
            this->AddEdge(node->Key, neighborNode->Key);
        }
    }
    return *this;
}

bool Graph::HasKey(int key) {
    return std::any_of(this->Nodes.begin(), this->Nodes.end(), [key](auto node) { return node->Key == key;});
}

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

Node *Graph::GetNode(int key) {
    for (auto node : this->Nodes) {
        if (node->Key == key)
            return node;
    }
    return nullptr;
}

void Graph::Print() {
    for (auto node : this->Nodes) {
        std::cout << "[ " << node->Key << " ]";
        for (auto neighborNode : node->Neighbors)
            std::cout << " -> " << neighborNode->Key;
        std::cout << std::endl;
    }
}
