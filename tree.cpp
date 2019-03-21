#include "tree.h"

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

void Tree::dfs () {
    dfs(0);
}

void Tree::dfs (int u) {
    Node root = nodes[u];
    cout << root.label << " ";
    for (Node node : root.children)
        dfs(node.label);
}


