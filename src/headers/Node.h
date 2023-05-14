/*****************************************************************//**
 * @file   Node.h
 * @brief  class representing the Node (Vertex) of the graph
 *
 * @author SIK0207
 * @date   13.05.2023
 *********************************************************************/

#pragma once

#include "common.h"

/**
 * @brief class representing the Node (Vertex) of the graph
 */
class Node {
public:
    int Key;
    std::vector<Node *> Neighbors;
    bool Visited;

    Node(int key);
};
