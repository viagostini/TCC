#include "../include/Node.hpp"

Node::Node (int label): label_(label) {}

int Node::label () const {
    return label_;
}

// int Node::depth () {
//     return depth_;
// }

// void Node::setDepth (int depth) {
//     depth_ = depth;
// }

// int Node::parent () {
//     return parent_;
// }

// void Node::setParent (int parent) {
//     parent_ = parent;
// }

vector<Node> Node::children () const {
    return children_;
}

void Node::add_child (Node child) {
    this->children_.push_back(child);
}
