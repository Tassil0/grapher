/*****************************************************************//**
 * @file   Iterator.cpp
 * @brief  Iterator class, holds the Graph data structure
 *
 * @author SIK0207
 * @date   13.05.2023
 *********************************************************************/

#include "headers/Iterator.h"

/**
 * @brief Iterator class constructor
 * @param graph
 */
Iterator::Iterator(const class Graph& graph) : Graph(graph) {
    this->Size = graph.Nodes.size();
    //this->ItGraph = graph; TODO: WHAT??
}
