#ifndef TREE_H
#define TREE_H

#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include "Edge.hpp"
#include "Node.hpp"

using std::stack;
using std::pair;
using std::vector;
using std::make_pair;
using std::max_element;

class Tree {
    private:
    int size_;
    vector<int> depth_;
    vector<int> parent_;

    public:
    Tree (int size, const Node *tree_root);
    const Node *root;
    int size () const;
    int depth () const;
    int depth (int u) const;
    int parent (int u) const;
    void dfs (Node *node, int depth);
};

#endif // TREE_H
