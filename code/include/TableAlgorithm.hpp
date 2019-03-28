#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "../include/tree.hpp"

using std::vector;

class TableAlgorithm {
    private:
    Tree tree;
    vector<vector<int>> table_;
    void dfsUtil_ (int u, int depth);

    public:
    TableAlgorithm (Tree &tree);
    vector<vector<int>> table ();
    int query (int u, int d);
};

#endif // TABLE_H