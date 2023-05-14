/*****************************************************************//**
 * \file   BFSIterator.cpp
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#include "headers/BFSIterator.h"

//BFSIterator::BFSIterator(const class Graph &graph) : Iterator(graph) {
////    this->Size = graph.Nodes.size();
////    this->Graph = graph;
////    this->Queue = 0;
//}

void BFSIterator::Reset() {
    auto tmp = this->Graph.Nodes.front();
    for (auto node : this->Graph.Nodes) {
        if (node->Key < tmp->Key)
            tmp = node;
        node->Visited = false;
    }
    this->Queue.push(tmp);
    tmp->Visited = true;
}

void BFSIterator::Next() {
    if (!this->Queue.empty()) {
        //this->Queue.front()->Visited = true;
        for (auto node : this->Queue.front()->Neighbors) {
            if (!node->Visited) {
                node->Visited = true;
                this->Queue.push(node);
            }
        }
        this->Queue.pop();
    }
    if (this->Queue.empty()) {
        for (auto node : this->Graph.Nodes) {
            if (!node->Visited) {
                this->Queue.push(node);
                node->Visited = true;
                return;
            }
        }
    }
}

// template for this
bool BFSIterator::IsEnd() {
    return this->Queue.empty() && std::all_of(this->Graph.Nodes.begin(), this->Graph.Nodes.end(), [](auto node) { return node->Visited; });
}

int BFSIterator::CurrentKey() {
    return this->Queue.front()->Key;
}