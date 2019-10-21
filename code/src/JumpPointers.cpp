#include "../include/JumpPointers.hpp"

JumpPointerLA::JumpPointerLA (const Tree* tree) {
    tree_ = tree;
    resize_tables();
    seen.resize(tree->size());
    for (int i = 0; i < tree->size(); i++)
        seen[i] = 0;
    set_jump_table();
    /*for (int i = 0; i < tree_->size(); i++) {
        for (int j = 0; j <= max_jumps; j++) {
            cout << jmp_[i][j] << "  ";
        }
        cout << endl << endl;
    }*/
}

int JumpPointerLA::query1 (int node, int depth) {
    if (depth < 0)
        throw std::invalid_argument("depth cannot be negative!");
    if (node < 0 || node >= tree_->size())
        throw std::invalid_argument("invalid node label!");
    if (depth > tree_->depth(node))
        return -1;

    int step = 0;
    int k = depth_[node] - depth;
    while (k > 0) {
        if (k % 2)
            node = jmp_[node][step];
        k /= 2;
        step++;
    }
    return node;
}

int JumpPointerLA::query2 (int node, int depth) {
    if (depth < 0)
        throw std::invalid_argument("depth cannot be negative!");
    if (node < 0 || node >= tree_->size())
        throw std::invalid_argument("invalid node label!");
    if (depth > tree_->depth(node))
        return -1;

    while (tree_->depth(node) != depth) {
        int step = get_msb(tree_->depth(node) - depth);
        //cout << "step = " << step << endl;
        node = jmp_[node][step];
    }
    return node;
}

int JumpPointerLA::get_msb (int x) {
    return 31 - __builtin_clz(x);
}

void JumpPointerLA::resize_tables() {
    int size = tree_->size();
    depth_.resize(size);
    max_jumps = ceil(log2(size));
    jmp_.assign(size, vector<int>(max_jumps + 1));
}

void JumpPointerLA::set_jump_table() {
    for (int node = 0; node < tree_->size(); node++)
        jmp_[node][0] = tree_->parent(node);

    for (int j = 1; j <= max_jumps; j++)
        for (int i = 0; i < tree_->size(); i++)
            jmp_[i][j] = jmp_[jmp_[i][j-1]][j-1];
}
