#include "../include/TableAlgorithm.hpp"

#include <iostream>
#include <cmath>

using std::endl;
using std::cout;
using std::max;

TableAlgorithm::TableAlgorithm (const Tree* tree) {
    tree_ = tree;
    resize_table();
    fill_table();
}

int TableAlgorithm::query (int node, int depth) const {
    if (depth < 0)
        throw std::invalid_argument("depth cannot be negative!");
    if (node < 0 || node >= tree_->size())
        throw std::invalid_argument("invalid node label!");
    if (depth > tree_->depth(node))
        return -1;
    return table_[node][depth];
}

void TableAlgorithm::resize_table() {
    int size = tree_->size();
    table_.resize(size);
    for (int i = 0; i < size; i++)
        table_[i].resize(tree_->depth(i) + 1);
}

void TableAlgorithm::fill_table() {
    for (int u = 0; u < tree_->size(); u++) {
        int v = u;
        table_[u][tree_->depth(u)] = u;
        int depth = max(0, tree_->depth(u) - 1);
        for (int i = tree_->depth(u)-1; i >= 0; i--) {
            table_[u][i] = tree_->parent(v);
            v = tree_->parent(u);
        }
    }
}

void TableAlgorithm::print_table() const {
    for (int i = 0; i < table_.size(); i++) {
        for (int j = 0; j < table_.size(); j++) {
            fprintf(stderr, "%d ", table_[i][j]);
        }
        fprintf(stderr, "\n");
    }
}


