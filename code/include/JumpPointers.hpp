#ifndef JUMP_H
#define JUMP_H

#include <vector>
#include <math.h>
#include <stdexcept>
#include <iostream>
#include "../include/Tree.hpp"

using std::vector;

class JumpPointerLA {
    private:
    int l_;
    const Tree* tree_;
    vector<int> depth_;
    vector<vector<int>> jmp_;
    void resize_tables();
    void dfs (int v, int p, int d);
    int get_msb (int x);

    public:
    JumpPointerLA (const Tree* tree);
    int query1 (int u, int d);
    int query2 (int u, int d);
};

#endif // JUMP_H
