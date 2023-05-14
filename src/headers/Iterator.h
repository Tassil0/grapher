/*****************************************************************//**
 * \file   Iterator.h
 * \brief  TODO: BRIEF
 *
 * \author SIK0207
 * \date   13.05.2023
 *********************************************************************/

#pragma once

#include "common.h"
#include "Graph.h"

class Iterator {
protected:
    unsigned long Size; // todo: remove
    Graph Graph;
public:
    explicit Iterator(const class Graph& graph);
};
