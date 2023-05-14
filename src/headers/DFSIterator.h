/*****************************************************************//**
 * \file   DFSIterator.h
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#pragma once

#include <stack>
#include "Graph.h"
#include "Iterator.h"

class DFSIterator : Iterator {
private:
    std::stack<Node *> Stack;
public:
    explicit DFSIterator(const class Graph &graph) : Iterator(graph) {};
    ~DFSIterator() = default;

    void Reset();
    void Next();
    bool IsEnd();
    int CurrentKey();
};
