#include "generators.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

void create_nodes (int n, vector<Node*>& nodes) {
    for (int i = 0; i < n; i++)
        nodes.push_back(new Node(i));
}

void build_balanced_kary_tree (int n, int k, vector<Node*>& nodes) {
    create_nodes(n, nodes);
    int logkn = (int) ceil((log(n) / log(k)));
    int i;
    for (i = 0; i < (n-1)/k; i++)
        for (int j = 1; j <= k; j++)
            nodes[i]->add_child(nodes[k*i+j]);
    for (int j = k*i+1; j < n; j++)
        nodes[i]->add_child(nodes[j]);

    for (int j = 0; j < n; j++) {
        cout << "node " << j << endl;
        for (auto child : nodes[j]->children)
            cout << child->label << " ";
        cout << endl;
    }
}