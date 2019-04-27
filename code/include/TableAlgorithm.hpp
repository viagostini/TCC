#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "../include/Tree.hpp"

using std::vector;

class TableAlgorithm {
    private:
    vector<vector<int>> table_;

    public:
    TableAlgorithm (const Tree& tree);
    void print_table () const;
    int query (int u, int d) const;
};

#endif // TABLE_H
