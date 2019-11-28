#include <iostream>
#include <cstdlib>
#include <chrono>
#include <utility>
#include <tuple>
#include <random>
#include <fstream>
#include "../generators/generators.hpp"
#include "../tests/include/TestUtils.hpp"
#include "../code/include/NaiveAlgorithm.hpp"

using namespace std;

int n, k;
string algo;

Tree *tree;

pair<int,int> random_query() {
    int node = rand() % n;
    int depth = rand() % (tree->depth(node) + 1);
    return make_pair(node, depth);
}

int main (int args, char* argv[]) {
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    int m = 10000000;
    
    string path = "input/";
    if (k == 1) 
        path.append("linear/query_linear_");
    else if (k == 2)
        path.append("binary/query_binary_");
    else if (k == 4)
        path.append("4ary/query_4ary_");

    path.append(argv[1]);

    ofstream query_file(path);

    vector<Node*> nodes;
    build_balanced_kary_tree(n, k, nodes);
    tree = new Tree(nodes.size(), nodes[0]);

    int node, depth;
    auto t1 = chrono::steady_clock::now();
    for (int i = 0; i < m; i++) {
        tie(node, depth) = random_query();
        query_file << node << " " << depth << "\n";
    }
    auto t2 = chrono::steady_clock::now();
    
    query_file.close();

    auto dt = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    cout << dt / 1e9 << endl;  // seconds

    delete tree;
}
