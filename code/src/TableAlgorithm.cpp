#include "../include/TableAlgorithm.hpp"

TableAlgorithm::TableAlgorithm (Tree& tree) {
    // allocating lookup table
    tree_ = tree;
    table_.resize(tree.size());
    for (int i = 0; i < tree.size(); i++)
        table_[i].resize(tree.size());
    // perform dfs to start filling table
    //dfsUtil_(0, 0);
    // depth(u) and depth(u)-1 has been filled for every u
    // for (Node node : tree.nodes()) {
    //     Node curr = node;
    //     int u = node.label();
    //     for (int i = node.depth()-2; i >= 0; i--) {
    //         int p = curr.parent();
    //         table_[u][i] = table_[p][i];
    //         curr = tree.nodes()[curr.parent()];
    //     }
    // }
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

int TableAlgorithm::query (int u, int d) {
    return table_[u][d];
}

