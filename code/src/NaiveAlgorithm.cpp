#include "../include/NaiveAlgorithm.hpp"

NaiveAlgorithm::NaiveAlgorithm (const Tree* tree) {
    tree_ = tree;
}

int NaiveAlgorithm::query (int node, int depth) const {
    if (depth < 0)
        throw std::invalid_argument("depth cannot be negative!");
    if (node < 0 || node >= tree_->size())
        throw std::invalid_argument("invalid node label!");
    if (depth > tree_->depth(node))
        return -1;
    
    while (tree_->depth(node) != depth) {
        node = tree_->parent(node);
    }

    return node;
}
