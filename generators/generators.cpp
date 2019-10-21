#include "generators.hpp"

void create_nodes (int n, vector<Node*>& nodes) {
    for (int i = 0; i < n; i++)
        nodes.push_back(new Node(i));
}

void build_balanced_kary_tree (int n, int k, vector<Node*>& nodes) {
    create_nodes(n, nodes);
    for (int i = 0; i < (n-1)/k; i++)
        for (int j = 1; j <= k; j++)
            nodes[i]->add_child(nodes[k*i+j]);
    int i = (n-1)/k;
    for (int j = k*i+1; j < n; j++)
        nodes[i]->add_child(nodes[j]);
}

void check_nodes (vector<Node*>& nodes) {
    for (int j = 0; j < nodes.size(); j++) {
        cout << "node " << j << endl;
        for (auto child : nodes[j]->children)
            cout << child->label << " ";
        cout << endl;
    }
}