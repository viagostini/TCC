#include "tree.hpp"

Edge::Edge (int from, int to): to(to), from(from) {}

Node::Node (int label): label(label) {}

void Node::add_child (Node child) {
    this->children.push_back(child);
}

Tree::Tree (int size, vector<Edge> edges) {
    this->size = size;
    for (int i = 0; i < size; i++) {
        Node node(i);
        nodes.push_back(node);
    }
    for (Edge e : edges)
        nodes[e.from].add_child(nodes[e.to]);
}

vector<int> Tree::dfs () {
    vector<int> ret;
    dfs(0, ret);
    return ret;
}

void Tree::dfs (int u, vector<int> &ret) {
    Node root = nodes[u];
    ret.push_back(root.label);
    //cout << root.label << " ";
    for (Node node : root.children)
        dfs(node.label, ret);
}


