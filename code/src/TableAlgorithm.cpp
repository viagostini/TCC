#include "../include/TableAlgorithm.hpp"

TableAlgorithm::TableAlgorithm (const Tree& tree) {
    table_.resize(tree.size());
    for (int i = 0; i < tree.size(); i++)
        table_[i].resize(tree.size());
    for (int u = 0; u < tree.size(); u++) {
        int v = u;
        table_[u][tree.depth(u)] = u;
        for (int i = tree.depth(u)-1; i >= 0; i--) {
            table_[u][i] = tree.parent(v);
            v = tree.parent(u);
        }
    }

    // for (int i = 0; i < tree.size(); i++) {
    //     for (int j = 0; j < tree.size(); j++) {
    //         fprintf(stderr, "%d ", table_[i][j]);
    //     }
    //     fprintf(stderr, "\n");
    // }
}

int TableAlgorithm::query (int u, int d) const {
    return table_[u][d];
}

