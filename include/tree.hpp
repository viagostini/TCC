#ifndef TREE_H
#define TREE_H

#include <vector>
#include "edge.hpp"
#include "node.hpp"

using std::vector;

class Tree {
    public:
    int size_;
    vector <Node> nodes_;

    Tree (int size, vector<Edge> edges);
    int size ();
    vector<Node> nodes ();
    vector<int> dfs ();
    void dfs (int u, vector<int> &ret);
};

#endif // TREE_H