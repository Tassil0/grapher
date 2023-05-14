/*****************************************************************//**
 * \file   Node.h
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#pragma once

#include "common.h"

class Node {
public:
    int Key;
    std::vector<Node *> Neighbors;
    bool Visited;

    Node(int key);
};
