/*****************************************************************//**
 * @file   Iterator.h
 * @brief  Header for Iterator parent class
 *
 * @author SIK0207
 * @date   13.05.2023
 *********************************************************************/

#pragma once

#include "common.h"
#include "Graph.h"

/**
 * @brief Class that hold the graph data structure
 */
class Iterator {
protected:
    unsigned long Size; // todo: remove
    Graph Graph;
public:
    explicit Iterator(const class Graph& graph);
};
