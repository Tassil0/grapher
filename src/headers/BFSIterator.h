/*****************************************************************//**
 * @file   BFSIterator.h
 * @brief  Class for the DFS Iterator
 *
 * @author SIK0207
 * @date   13.05.2023
 *********************************************************************/

#pragma once

#include <queue>
#include "Iterator.h"
#include "Graph.h"

class BFSIterator : Iterator {
private:
    std::queue<Node *> Queue;
public:
    explicit BFSIterator(const class Graph &graph) : Iterator(graph) {};
    ~BFSIterator() = default;

    void Reset();
    void Next();
    bool IsEnd();
    int CurrentKey();
};
