#ifndef NODE_H
#define NODE_H

#include <vector>

using std::vector;

class Node {
    private:
    int label_;
    // int depth_;
    // int parent_;
    vector<Node> children_;

    public:
    Node (int label);
    int label () const;
    // int depth ();
    // int parent ();
    // void setDepth (int depth);
    // void setParent (int parent);
    vector<Node> children () const;
    void add_child (Node child);
};

#endif // NODE_H
