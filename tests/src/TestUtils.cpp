#include "../include/TestUtils.hpp"

int naive_check (Tree *tree, int node, int depth) {
    while (tree->depth(node) != depth)
        node = tree->parent(node);
    return node;
}