#include <iostream>
#include <cstdlib>
#include <chrono>
#include <utility>
#include "../generators/generators.hpp"
#include "../tests/include/TestUtils.hpp"
#include "../code/include/PreOrder.hpp"

using namespace std;

int main (int args, char* argv[]) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    
    vector<Node*> nodes;
    build_balanced_kary_tree(n, k, nodes);
    Tree *tree = new Tree(nodes.size(), nodes[0]);

    auto t1 = chrono::steady_clock::now();
    PreOrder *preorder = new PreOrder(tree);
    auto t2 = chrono::steady_clock::now();
    
    auto dt = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    cout << dt / 1e9 << endl;  // seconds

    delete preorder;
    delete tree;
}
