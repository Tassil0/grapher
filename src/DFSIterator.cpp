/*****************************************************************//**
 * \file   DFSIterator.cpp
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#include "headers/DFSIterator.h"

void DFSIterator::Reset() {
    auto tmp = this->Graph.Nodes.front();
    for (auto node : this->Graph.Nodes) {
        if (node->Key < tmp->Key)
            tmp = node;
        node->Visited = false;
    }
    this->Stack.push(tmp);
    tmp->Visited = true;
}

void DFSIterator::Next() {
    if (!this->Stack.empty()) {
        auto tmp = this->Stack.top();
        //tmp->Visited = true;
        this->Stack.pop();
        for (auto node : tmp->Neighbors) {
            if (!node->Visited) {
                this->Stack.push(node);
                node->Visited = true;
            }
        }
    }
    if (this->Stack.empty()) {
        for (auto node : this->Graph.Nodes) {
            if (!node->Visited) {
                this->Stack.push(node);
                node->Visited = true;
                return;
            }
        }
    }
}

bool DFSIterator::IsEnd() {
    return this->Stack.empty() && std::all_of(this->Graph.Nodes.begin(), this->Graph.Nodes.end(), [](auto node) { return node->Visited; });
}

int DFSIterator::CurrentKey() {
    return this->Stack.top()->Key;
}