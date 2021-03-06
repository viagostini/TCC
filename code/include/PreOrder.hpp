#ifndef PREORDER_H
#define PREORDER_H

#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "../include/Tree.hpp"

using std::cout;
using std::endl;
using std::prev;
using std::tuple;
using std::vector;
using std::make_tuple;
using std::upper_bound;

class PreOrder {
    private:
    const Tree* tree_;
    vector<int> x;
    vector<int> y;
    vector<vector<int>> traversal_;
    void dfs(Node *node, int depth, int& id);

    public:
    PreOrder (const Tree* tree);
    int query (int node, int depth) const;
};

#endif // PREORDER_H
