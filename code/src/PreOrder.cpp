#include "../include/PreOrder.hpp"

PreOrder::PreOrder (const Tree* tree) {
    tree_ = tree;
    x.resize(tree_->size());
    y.resize(tree_->size());
    int id = 0;
    dfs(const_cast<Node*>(tree_->root), 0, id);

    /* for (int i = 0; i < traversal_.size(); i++) {
        cout << "d = " << i << endl;
        for (int j = 0; j < traversal_[i].size(); j++)
            cout << y[traversal_[i][j]] << " ";
        cout << endl;
    } */

}

int PreOrder::query (int node, int depth) const {
    if (depth < 0)
        throw std::invalid_argument("depth cannot be negative!");
    if (node < 0 || node >= tree_->size())
        throw std::invalid_argument("invalid node label!");
    if (depth > tree_->depth(node))
        return -1;
    
    auto idx = upper_bound(traversal_[depth].begin(),
                          traversal_[depth].end(),
                          x[node]);
    return y[*prev(idx)];
}

void PreOrder::dfs (Node *node, int depth, int& id) {
    stack<tuple<Node*, int>> stack;
    stack.push(make_tuple(node, depth));
    while (!stack.empty()) {
        std::tie(node, depth) = stack.top();
        stack.pop();
        if (traversal_.size() <= depth)
            traversal_.push_back(vector<int>());

        x[node->label] = id;
        y[id] = node->label;

        traversal_[depth].push_back(id++);
    
        for (Node *child : node->children)
            stack.push(make_tuple(child, depth+1));
    }
}
