#ifndef NODE_H
#define NODE_H

#include <vector>

using std::vector;

class Node {
    public:
    const int label;
    vector<Node*> children;

    Node (int label);
    void add_child (Node *child);
};

#endif // NODE_H
