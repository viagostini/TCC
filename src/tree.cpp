#include "../include/tree.hpp"

Tree::Tree () {
    int size = 0;
}

Tree::Tree (int size, vector<Edge> edges) {
    size_ = size;
    depth_.resize(size);
    parent_.resize(size);
    for (int i = 0; i < size; i++) {
        Node node(i);
        nodes_.push_back(node);
    }
    for (Edge e : edges) {
        int u = e.from();
        int v = e.to();
        nodes_[u].add_child(nodes_[v]);
        depth_[v] = depth_[u] + 1;
        parent_[v] = u;
    }
}

int Tree::size () {
    return size_;
}

int Tree::depth (int u) {
    return depth_[u];
}

int Tree::parent (int u) {
    return parent_[u];
}

vector<Node> Tree::nodes () {
    return nodes_;
}

vector<int> Tree::dfs () {
    vector<int> ret;
    dfs(0, ret);
    return ret;
}

void Tree::dfs (int u, vector<int> &ret) {
    Node root = nodes_[u];
    ret.push_back(root.label());
    for (Node node : root.children())
        dfs(node.label(), ret);
}


