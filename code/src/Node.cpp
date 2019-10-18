#include "../include/Node.hpp"

Node::Node (int label): label(label) {}

void Node::add_child (Node *child) {
    this->children.push_back(child);
}
