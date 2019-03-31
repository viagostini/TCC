#include "../include/Edge.hpp"

Edge::Edge (int from, int to) {
    if (from == to) {
        fprintf(stderr, "Edges can't be loops!");
        exit(EXIT_FAILURE);
    }
    from_ = from;
    to_ = to;
}

int Edge::from () {
    return from_;
}

int Edge::to () {
    return to_;
}