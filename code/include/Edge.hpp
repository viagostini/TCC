#ifndef EDGE_H
#define EDGE_H

#include <cstdio>
#include <cstdlib>
#include <utility>

using std::pair;

typedef pair<int,int> Edge;
#define from first
#define to second
#define make_edge make_pair

// class Edge {
//     public:
//     int from_;
//     int to_;

//     Edge (int from, int to);
//     int from ();
//     int to ();
// };

#endif // EDGE_H