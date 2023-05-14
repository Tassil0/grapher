/*****************************************************************//**
 * @file   Node.cpp
 * @brief  class representing the Node (Vertex) of the graph
 *
 * @author SIK0207
 * @date   13.05.2023
 *********************************************************************/

#include "headers/Node.h"

/**
 * @brief node constructor
 * @param key
 */
Node::Node(int key) {
    this->Key = key;
    this->Visited = false;
}