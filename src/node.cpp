#include "../include/node.hpp"

Node::Node (int label): label_(label) {}

int Node::label () {
    return label_;
}

vector<Node> Node::children () {
    return children_;
}

void Node::add_child (Node child) {
    this->children_.push_back(child);
}