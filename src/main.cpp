/*****************************************************************//**
 * \file   main.cpp
 * \brief  Main file for testing and demostration purposes
 *
 * \author SIK0207
 * \date   May 2023
 *********************************************************************/

#include <array>
#include <chrono>
#include "headers/common.h"
#include "headers/Graph.h"
#include "headers/DFSIterator.h"
#include "headers/BFSIterator.h"

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::chrono::steady_clock;
using std::chrono::duration;
using std::cout;
using std::endl;

void printSep();
void loadIterate(std::string filename);

std::array<std::string, 4> testFiles = {"graf-big.txt", "graph1.txt", "graph2.txt", "graph3.txt"};
//std::array<std::string, 3> testFiles = {"graph1.txt", "graph2.txt", "graph3.txt"};

int main(int argc, char **argv) {
    switch (argc) {
        case 1:
            for (auto testFile : testFiles)
                loadIterate("testdata/" + testFile);
            break;
        case 2:
            loadIterate(std::string(argv[1]));
            break;
        default:
            std::cout << "invalid arguments";
    }
    return 0;
}

void printSep() {
    std::cout << std::endl << "=======================================" << std::endl;
}

std::string fmtDelta(time_point<steady_clock> t1, time_point<steady_clock> t2) {
    return std::to_string(duration<double, std::milli>(t2 - t1).count()) + "ms";
}

void loadIterate(std::string filename) {
    printSep();
    std::cout << filename << std::endl << std::endl;
    auto t1 = high_resolution_clock::now();
    auto graph = new Graph(filename);
    auto t2 = high_resolution_clock::now();
    std::cout << "## " << filename << " read time: " << fmtDelta(t1, t2) << std::endl;
    t1 = high_resolution_clock::now();
    graph->Print();
    t2 = high_resolution_clock::now();
    cout << "## " << filename << " print time: " << fmtDelta(t1, t2) << endl;
    cout << endl << "## DFS iteration: ";
    t1 = high_resolution_clock::now();
    DFSIterator dfsIter(*graph);
    for (dfsIter.Reset(); !dfsIter.IsEnd(); dfsIter.Next()) {
        cout << dfsIter.CurrentKey() << " ";
    }
    t2 = high_resolution_clock::now();
    cout << endl << "## " << filename << " DFS iteration time: " << fmtDelta(t1, t2) << endl;
    cout << endl << "## BFS iteration: ";
    t1 = high_resolution_clock::now();
    BFSIterator bfsIter(*graph);
    for (bfsIter.Reset(); !bfsIter.IsEnd(); bfsIter.Next()) {
        cout << bfsIter.CurrentKey() << " ";
    }
    t2 = high_resolution_clock::now();
    cout << endl << "## " << filename << " BFS iteration time: " << fmtDelta(t1, t2) << endl;
}