#include <iostream>
#include <cstdlib>
#include <chrono>
#include <utility>
#include <tuple>
#include <random>
#include <fstream>
#include "../generators/generators.hpp"
#include "../tests/include/TestUtils.hpp"
#include "../code/include/TableAlgorithm.hpp"

using namespace std;

int main (int args, char* argv[]) {
    volatile int q;
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int m = 10000000;
    
    string path = "input/";
    if (k == 1) 
        path.append("linear/query_linear_");
    else if (k == 2)
        path.append("binary/query_binary_");
    else if (k == 4)
        path.append("4ary/query_4ary_");

    path.append(argv[1]);

    fstream query_file(path, ios_base::in);

    vector<Node*> nodes;
    build_balanced_kary_tree(n, k, nodes);
    Tree *tree = new Tree(nodes.size(), nodes[0]);
    TableAlgorithm *table = new TableAlgorithm(tree);

    int node, depth;

    //vector<pair<int,int>> queries(m);
    vector<int> query_nodes(m);
    vector<int> query_depths(m);
    for (int i = 0; i < m; i++) {
        query_file >> node >> depth;
        query_nodes[i] = node;
        query_depths[i] = depth;
    }
    
    query_file.close();

    auto t1 = chrono::steady_clock::now();
    
    for (int i = 0; i < m; i++) {
        q = table->query(query_nodes[i], query_depths[i]);
    }

    auto t2 = chrono::steady_clock::now();
    
    auto dt = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    cout << dt / 1e9 << endl;  // seconds

    delete table;
    delete tree;
}
