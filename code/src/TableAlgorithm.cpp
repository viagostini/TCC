#include "../include/TableAlgorithm.hpp"

TableAlgorithm::TableAlgorithm (const Tree& tree) {
    int tree_size = tree.size();
    table_.resize(tree_size);
    for (int i = 0; i < tree_size; i++)
        table_[i].resize(tree_size);
    for (int u = 0; u < tree_size; u++) {
        int v = u;
        table_[u][tree.depth(u)] = u;
        for (int i = tree.depth(u)-1; i >= 0; i--) {
            table_[u][i] = tree.parent(v);
            v = tree.parent(u);
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

int TableAlgorithm::query (int u, int d) const {
    return table_[u][d];
}

