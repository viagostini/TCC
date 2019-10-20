#include <stdexcept>
#include "../include/catch.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/Tree.hpp"
#include "../../generators/generators.hpp"

TEST_CASE ("Tree", "[tree]") {
    SECTION ("Default tree") {
        struct DefaultTree default_tree;
        
        vector<Node*> nodes;
        for (int i = 0; i < default_tree.size; i++) {
            Node *node = new Node(i);
            nodes.push_back(node);
        }
        for (const Edge& e : default_tree.edges) {
            nodes[e.from]->add_child(nodes[e.to]);
        }

        Tree *tree = new Tree(default_tree.size, nodes[0]);

        SECTION ("Tree has a size")
            REQUIRE(tree->size() == default_tree.size);

        SECTION ("Tree has parent function") {
            REQUIRE(tree->parent(0) == 0);
            REQUIRE(tree->parent(1) == 0);
            REQUIRE(tree->parent(2) == 0);

            SECTION ("Parent function throws when node is invalid") {
                REQUIRE_THROWS_AS(tree->parent(-1), std::invalid_argument);
                REQUIRE_THROWS_AS(tree->parent(tree->size()), std::invalid_argument);
            }
        }

        SECTION ("Tree has depth function") {
            REQUIRE(tree->depth(0) == 0);
            REQUIRE(tree->depth(1) == 1);
            REQUIRE(tree->depth(2) == 1);

            SECTION ("Depth function throws when node is invalid") {
                REQUIRE_THROWS_AS(tree->depth(-1), std::invalid_argument);
                REQUIRE_THROWS_AS(tree->depth(tree->size()), std::invalid_argument);
            }
        }
    }
    SECTION ("Linear Tree") {
        int n = 25;
        vector<Node*> nodes;
        build_balanced_kary_tree(n, 1, nodes);
        Tree *tree = new Tree(nodes.size(), nodes[0]);
        
        SECTION ("Tree has a size")
            REQUIRE(tree->size() == n);

        SECTION ("Tree has parent function") {
            REQUIRE(tree->parent(0) == 0);
            for (int i = 1; i < n; i++)
                REQUIRE(tree->parent(i) == i-1);

            SECTION ("Parent function throws when node is invalid") {
                REQUIRE_THROWS_AS(tree->parent(-1), std::invalid_argument);
                REQUIRE_THROWS_AS(tree->parent(tree->size()), std::invalid_argument);
            }
        }

        SECTION ("Tree has depth function") {
            for (int i = 0; i < n; i++)
                REQUIRE(tree->depth(i) == i);

            SECTION ("Depth function throws when node is invalid") {
                REQUIRE_THROWS_AS(tree->depth(-1), std::invalid_argument);
                REQUIRE_THROWS_AS(tree->depth(tree->size()), std::invalid_argument);
            }
        }
    }
}
