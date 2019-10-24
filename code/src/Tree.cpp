#include "../include/Tree.hpp"

Tree::Tree (int size, const Node *tree_root) {
    root = tree_root;
    size_ = size;

    depth_.resize(size);
    parent_.resize(size);
    
    dfs(const_cast<Node *>(root), 0);
}

int Tree::size () const {
    return size_;
}

int Tree::depth (int u) const {
    if (u >= size_)
        throw std::invalid_argument("invalid node label!");
    if (u < 0)
        throw std::invalid_argument("invalid node label!");
    return depth_[u];
}

int Tree::parent (int u) const {
    if (u >= size_)
        throw std::invalid_argument("invalid node label!");
    if (u < 0)
        throw std::invalid_argument("invalid node label!");
    return parent_[u];
}

void Tree::dfs (Node *node, int depth) {
    stack<pair<Node*, int>> stack;
    stack.push(make_pair(node, depth));
    while (!stack.empty()) {
        auto s = stack.top();
        stack.pop();
        node = s.first;
        depth = s.second;
        depth_[node->label] = depth;
        for (Node *child : node->children) {
            parent_[child->label] = node->label;
            stack.push(make_pair(child, depth+1));
        }
    }
}


