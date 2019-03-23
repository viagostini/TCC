#include "../include/edge.hpp"

Edge::Edge (int from, int to): from_(from), to_(to) {}

int Edge::from () {
    return from_;
}

int Edge::to () {
    return to_;
}