#ifndef LINEAR_GEN_H
#define LINEAR_GEN_H

#include <vector>
#include <iostream>
#include <cmath>
#include "../code/include/Tree.hpp"

using std::cout;
using std::endl;
using std::vector;

void check_nodes (vector<Node*>& nodes);
void create_nodes (int n, vector<Node*>& nodes);
void build_balanced_kary_tree (int n, int k, vector<Node*>& nodes);

#endif // LINEAR_GEN_H