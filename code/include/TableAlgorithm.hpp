#ifndef TABLE_H
#define TABLE_H

#include <cmath>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "../include/Tree.hpp"

using std::endl;
using std::cout;
using std::max;
using std::vector;

class TableAlgorithm {
    private:
    const Tree* tree_;
    vector<vector<int>> table_;
    void resize_table ();
    void fill_table ();

    public:
    TableAlgorithm (const Tree* tree);
    void print_table () const;
    int query (int u, int d) const;
};

#endif // TABLE_H
