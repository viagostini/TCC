#include "../include/edge.hpp"
#include "../include/node.hpp"
#include "../include/tree.hpp"

Tree::Tree (int size, vector<Edge> edges) {
    this->size_ = size;
    for (int i = 0; i < size; i++) {
        Node node(i);
        nodes_.push_back(node);
    }
    for (Edge e : edges)
        nodes_[e.from()].add_child(nodes_[e.to()]);
}

int Tree::size () {
    return this->size_;
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


