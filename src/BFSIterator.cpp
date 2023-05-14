/*****************************************************************//**
 * @file   BFSIterator.cpp
 * @brief  Class for the BFS Iterator
 *
 * @author SIK0207
 * @date   13.05.2023
 *********************************************************************/

#include "headers/BFSIterator.h"

/**
 * @brief metoda uloží do zásobníku vrchol grafu s nejnižším číslem. Iterace začíná tímto vrcholem.
 */
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

/**
 * @brief funkce posune aktuální vrchol iterátoru na následující vrchol.
 */
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

/**
 * @brief bude vracet true pokud je iterace ukončena, jinak vrací false. Iterace je ukončena, pokud
 *        je fronta prázdná a všechny vrcholy byly označeny jako zpracované.
 * @return boolean
 */
bool BFSIterator::IsEnd() {
    return this->Queue.empty() && std::all_of(this->Graph.Nodes.begin(), this->Graph.Nodes.end(), [](auto node) { return node->Visited; });
}

/**
 * @brief vrací hodnotu v aktuálním vrcholu
 * @return int
 */
int BFSIterator::CurrentKey() {
    return this->Queue.front()->Key;
}