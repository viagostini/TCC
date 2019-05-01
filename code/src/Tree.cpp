#include "../include/Tree.hpp"

Tree::Tree () {
    int size = 0;
}

Tree::Tree (int size, const vector<Edge>& edges) {
    size_ = size;
    depth_.resize(size);
    parent_.resize(size);
    for (int i = 0; i < size; i++) {
        Node node(i);
        nodes_.push_back(node);
    }
    for (const Edge& e : edges) {
        nodes_[e.from].add_child(nodes_[e.to]);
        depth_[e.to] = depth_[e.from] + 1;
        parent_[e.to] = e.from;
    }
}

int Tree::size () const {
    return size_;
}

int Tree::depth (int u) const {
    if (u >= size_)
        throw std::invalid_argument("invalid node label!");
    return depth_[u];
}

int Tree::parent (int u) const {
    if (u >= size_)
        throw std::invalid_argument("invalid node label!");
    return parent_[u];
}

vector<Node> Tree::nodes () const {
    return nodes_;
}

vector<int> Tree::dfs () const {
    vector<int> ret;
    dfs(0, ret);
    return ret;
}

void Tree::dfs (int u, vector<int>& ret) const {
    Node root = nodes_[u];
    ret.push_back(root.label());
    for (Node node : root.children())
        dfs(node.label(), ret);
}


