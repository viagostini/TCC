#ifndef NAIVE_H
#define NAIVE_H

#include <stdexcept>
#include <iostream>
#include "../include/Tree.hpp"

class NaiveAlgorithm {
    private:
    const Tree* tree_;

    public:
    NaiveAlgorithm (const Tree* tree);
    int query (int u, int d) const;
};

#endif // NAIVE_H
