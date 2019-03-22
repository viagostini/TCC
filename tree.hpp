#ifndef TREE_H
#define TREE_H

#include <bits/stdc++.h>

using namespace std;

class Edge {
    public:
    int from;
    int to;

    Edge (int from, int to);
};

class Node {
    public:
    int label;
    vector<Node> children;

    Node (int label);
    void add_child (Node child);
};

class Tree {
    public:
    int size;
    vector <Node> nodes;

    Tree (int size, vector<Edge> edges);
    vector<int> dfs ();
    void dfs (int u, vector<int> &ret);
};

#endif