#include <vector>
#include "../../code/include/Tree.hpp"

using std::vector;

struct EmptyTree {
    int size = 0;
    vector<Edge> edges = {};
};

struct DefaultTree {
    int size = 7;
    vector<Edge> edges = {
        make_edge(0, 1),
        make_edge(0, 2),
        make_edge(0, 3),
        make_edge(2, 4),
        make_edge(2, 5),
        make_edge(3, 6)
    };
};

