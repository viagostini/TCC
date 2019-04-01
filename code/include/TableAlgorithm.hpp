#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "../include/Tree.hpp"

using std::vector;

class TableAlgorithm {
    private:
    Tree tree_;
    vector<vector<int>> table_;
    void dfsUtil_ (int u, int depth);

    public:
    TableAlgorithm (Tree& tree);
    vector<vector<int>> table ();
    int query (int u, int d);
};

#endif // TABLE_H