/*****************************************************************//**
 * \file   Graph.h
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#pragma once

#include "common.h"
#include "Node.h"

class Graph {
private:
    std::string Name;
public:
    std::vector<Node *> Nodes;

    explicit Graph(std::string &fileName);
    ~Graph() = default;
    Graph& operator=(const Graph &rhs);

    bool HasKey(int key);
    void AddEdge(int nodeKey, int neighborKey);
    Node* GetNode(int key);
    void SortNodes();
    void Print();
};
