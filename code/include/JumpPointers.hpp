#ifndef JUMP_H
#define JUMP_H

#include <vector>
#include <math.h>
#include <stdexcept>
#include <iostream>
#include "../include/Tree.hpp"

using std::cout;
using std::endl;
using std::vector;

class JumpPointers {
    private:
    int max_jumps;
    const Tree* tree_;
    vector<int> depth_;
    vector<vector<int>> jmp_;
    void resize_tables();
    void set_jump_table();
    int get_msb (int x);

    public:
    JumpPointers (const Tree* tree);
    int query (int u, int d);
};

#endif // JUMP_H
