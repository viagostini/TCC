#include <bits/stdc++.h>

using namespace std;

typedef int Node;

class Tree {
    public:
        int V, E;
        vector< pair<Node,Node> > edges;
        vector< vector<Node> > adjacency_list;
        
        Tree (int V, int E, vector< pair<Node,Node> > edges) {
            this->V = V;
            this->E = E;
            this->edges = edges;

            create_tree();
            print_tree();
        };

        ~Tree () {};

        void add_edge (Node u, Node v);
        void create_tree ();
        void print_tree ();
        void dfs (Node root);
        void euler_tour (Node root);
};

void Tree::add_edge (Node u, Node v) {
    adjacency_list[u].push_back(v);
}

void Tree::create_tree () {
    adjacency_list.resize(V);
    // sort(edges.begin(), edges.end());
    for (auto edge : edges)
        adjacency_list[edge.first].push_back(edge.second);
    
    for (Node i = 0; i < V; i++)
        sort(adjacency_list[i].begin(), adjacency_list[i].end());
}

void Tree::print_tree () {
    cout << "Tree's adjacency list:" << endl;
    for (Node i = 0; i < adjacency_list.size(); i++) {
        cout << "Node " << i << ": ";
        for (Node j = 0; j < adjacency_list[i].size(); j++) {
            cout << adjacency_list[i][j] << " ";
        }
        cout << endl;
    }
}

void Tree::dfs (Node root) {
    cout << root << " ";
    for (Node neighbour : adjacency_list[root])
        dfs(neighbour);
}

void Tree::euler_tour (Node root) {
    cout << root << " ";
    for (Node neighbour : adjacency_list[root]) {
        euler_tour(neighbour);
        cout << root << " ";
    }
}

int main () {
    int V, E;
    vector<pair<int,int> > edges;

    cout << "Input number of nodes:" << endl;
    
    cin >> V;
    E = V-1;
    
    cout << "Input edge list:" << endl;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u,v));
    }

    Tree tree = Tree(V, E, edges);
    tree.dfs(0);
    cout << endl;
    tree.euler_tour(0);
}