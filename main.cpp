#include "tree.h"

int main () {
    int size;
    vector<Edge> edges;

    //cout << "Enter size of desired tree:" << endl;
    cin >> size;
    //cout << "Give edge list:" << endl;
    for (int i = 0; i < size-1; i++) {
        int from, to;
        cin >> from >> to;
        Edge e(from, to);
        edges.push_back(e);
    }
    Tree tree(size, edges);
    cout << "Tree size:" << endl;
    cout << tree.size << endl << endl;
    cout << "DFS Order:" << endl;
    tree.dfs();
}