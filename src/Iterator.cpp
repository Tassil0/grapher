/*****************************************************************//**
 * \file   Iterator.cpp
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#include "headers/Iterator.h"

Iterator::Iterator(const class Graph& graph) : Graph(graph) {
    this->Size = graph.Nodes.size();
    //this->ItGraph = graph; TODO: WHAT??
}
