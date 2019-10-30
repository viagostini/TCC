#include "../include/JumpPointers.hpp"

JumpPointers::JumpPointers (const Tree* tree) {
    tree_ = tree;
    resize_tables();
    set_jump_table();
}

int JumpPointers::query (int node, int depth) {
    if (depth < 0)
        throw std::invalid_argument("depth cannot be negative!");
    if (node < 0 || node >= tree_->size())
        throw std::invalid_argument("invalid node label!");
    if (depth > tree_->depth(node))
        return -1;

    while (tree_->depth(node) != depth) {
        int step = get_msb(tree_->depth(node) - depth);
        node = jmp_[node][step];
    }
    return node;
}

int JumpPointers::get_msb (int x) {
    return 31 - __builtin_clz(x);
}

void JumpPointers::resize_tables() {
    int size = tree_->size();
    depth_.resize(size);
    max_jumps = ceil(log2(size));
    jmp_.assign(size, vector<int>(max_jumps + 1));
}

void JumpPointers::set_jump_table() {
    for (int node = 0; node < tree_->size(); node++)
        jmp_[node][0] = tree_->parent(node);

    for (int j = 1; j <= max_jumps; j++)
        for (int i = 0; i < tree_->size(); i++)
            jmp_[i][j] = jmp_[jmp_[i][j-1]][j-1];
}
