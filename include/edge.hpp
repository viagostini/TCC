#ifndef EDGE_H
#define EDGE_H

#include <cstdio>
#include <cstdlib>

class Edge {
    public:
    int from_;
    int to_;

    Edge (int from, int to);
    int from ();
    int to ();
};

#endif // EDGE_H