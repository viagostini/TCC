#ifndef TREE_H
#define TREE_H

#include <vector>
#include <utility>
#include "Edge.hpp"
#include "Node.hpp"

using std::pair;
using std::vector;
using std::make_pair;

class Tree {
    private:
    int size_;
    vector<int> depth_;
    vector<int> parent_;
    vector<Node> nodes_;

    public:
    Tree ();
    Tree (int size, const vector<Edge>& edges);
    int size ();
    int depth (int u);
    int parent (int u);
    vector<Node> nodes ();
    vector<int> dfs ();
    void dfs (int u, vector<int>& ret);
};

#endif // TREE_H