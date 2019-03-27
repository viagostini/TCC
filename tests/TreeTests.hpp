#ifndef TREE_TESTS_H
#define TREE_TESTS_H

#include "../include/tree.hpp"

struct EmptyTree {
    int size = 0;
    vector<Edge> edges = {};
};

struct DefaultTree {
    int size = 7;
    vector<Edge> edges = {
        Edge(0, 1),
        Edge(0, 2),
        Edge(0, 3),
        Edge(2, 4),
        Edge(2, 5),
        Edge(3, 6)
    };
};

#endif // TREE_TESTS_H