#include "../include/JumpPointers.hpp"

JumpPointerLA::JumpPointerLA (const Tree* tree) {
    tree_ = tree;
    resize_tables();
    dfs(0, 0, 0);
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

    while (depth_[node] != depth) {
        int step = get_msb(depth_[node] - depth);
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
    l_ = ceil(log2(size));
    jmp_.assign(size, vector<int>(l_+1));
}

void JumpPointerLA::dfs(int v, int p, int d) {
    depth_[v] = d;
    jmp_[v][0] = p;
    
    for (int i = 1; i <= l_; i++)
        jmp_[v][i] = jmp_[jmp_[v][i-1]][i-1];
    
    for (Node *u: tree_->nodes()[v]->children())
        if (u->label() != p)
            dfs(u->label(), v, d+1);
}
