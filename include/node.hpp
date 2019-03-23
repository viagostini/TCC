#ifndef NODE_H
#define NODE_H

#include <vector>

using std::vector;

class Node {
    public:
    int label_;
    vector<Node> children_;

    Node (int label);
    int label ();
    vector<Node> children ();
    void add_child (Node child);
};

#endif // NODE_H