#include <stdexcept>
#include <cmath>
#include "../include/catch.hpp"
#include "../../generators/generators.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/PreOrder.hpp"

int solve (Tree *tree, int node, int depth) {
    int sum = 0;
    int k = tree->depth(node) - depth;
    for (int i = 0; i < k; i++)
        sum += (int) pow(4, i);
    return floor( (node - sum) / (int) pow(4, k) );
}

TEST_CASE ("PreOrder", "[preorder]") {
    SECTION ("Linear Tree") {
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
        PreOrder *preorder = new PreOrder(tree);

        SECTION ("Has a query function") {
            REQUIRE(preorder->query(0,0) == 0);
            REQUIRE(preorder->query(1,0) == 0);
            REQUIRE(preorder->query(2,0) == 0);
            REQUIRE(preorder->query(2,1) == 2);
            REQUIRE(preorder->query(3,0) == 0);
            REQUIRE(preorder->query(3,1) == 3);
            REQUIRE(preorder->query(4,0) == 0);
            REQUIRE(preorder->query(4,1) == 2);
            REQUIRE(preorder->query(4,2) == 4);
            REQUIRE(preorder->query(5,0) == 0);
            REQUIRE(preorder->query(5,1) == 2);
            REQUIRE(preorder->query(5,2) == 5);
            REQUIRE(preorder->query(6,0) == 0);
            REQUIRE(preorder->query(6,1) == 3);
            REQUIRE(preorder->query(6,2) == 6);

            SECTION ("Query function returns -1 if there is no answer") {
                REQUIRE(preorder->query(1, tree->size()) == -1);
                REQUIRE(preorder->query(1, tree->size()) == -1);
            }

            SECTION ("Query function throws if negative depth") {
                REQUIRE_THROWS_AS(preorder->query(1, -1), std::invalid_argument);
                REQUIRE_THROWS_AS(preorder->query(1, -1), std::invalid_argument);
            }

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(preorder->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(preorder->query(tree->size(), 0), std::invalid_argument);
                REQUIRE_THROWS_AS(preorder->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(preorder->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
    SECTION ("Linear Tree") {
        int n = 15;
        vector<Node*> nodes;
        build_balanced_kary_tree(n, 1, nodes);
        Tree *tree = new Tree(nodes.size(), nodes[0]);
        PreOrder *preorder = new PreOrder(tree);

        SECTION ("Has a query function") {
            for (int i = 0; i < n; i++) {
                for (int j = tree->depth(i); j >= 0; j--) {
                    REQUIRE(preorder->query(i, j) == j);
                }
            }

            SECTION ("Query function returns -1 if there is no answer") {
                REQUIRE(preorder->query(1, tree->size()) == -1);
                REQUIRE(preorder->query(1, tree->size()) == -1);
            }

            SECTION ("Query function throws if negative depth") {
                REQUIRE_THROWS_AS(preorder->query(1, -1), std::invalid_argument);
            }

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(preorder->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(preorder->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
    SECTION ("Binary Tree") {
        int n = 2178;
        vector<Node*> nodes;
        build_balanced_kary_tree(n, 2, nodes);
        Tree *tree = new Tree(nodes.size(), nodes[0]);
        PreOrder *preorder = new PreOrder(tree);

        SECTION ("Has a query function") {
            for (int node = 0; node < n; node++) {
                for (int depth = 0; depth <= tree->depth(node); depth++) {
                    REQUIRE(preorder->query(node, depth) == naive_check(tree, node, depth));
                }
            }
            SECTION ("Query function returns -1 if there is no answer") {
                REQUIRE(preorder->query(1, tree->size()) == -1);
                REQUIRE(preorder->query(1, tree->size()) == -1);
            }

            SECTION ("Query function throws if negative depth") {
                REQUIRE_THROWS_AS(preorder->query(1, -1), std::invalid_argument);
            }

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(preorder->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(preorder->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
    SECTION ("4-ary Tree") {
        int n = 2178;
        vector<Node*> nodes;
        build_balanced_kary_tree(n, 4, nodes);
        Tree *tree = new Tree(nodes.size(), nodes[0]);
        PreOrder *preorder = new PreOrder(tree);

        SECTION ("Has a query function") {
            for (int node = 0; node < n; node++) {
                for (int depth = 0; depth <= tree->depth(node); depth++) {
                    REQUIRE(preorder->query(node, depth) == naive_check(tree, node, depth));
                    REQUIRE(preorder->query(node, depth) == solve(tree, node, depth));
                }
            }

            SECTION ("Query function returns -1 if there is no answer") {
                REQUIRE(preorder->query(1, tree->size()) == -1);
                REQUIRE(preorder->query(1, tree->size()) == -1);
            }

            SECTION ("Query function throws if negative depth") {
                REQUIRE_THROWS_AS(preorder->query(1, -1), std::invalid_argument);
            }

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(preorder->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(preorder->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
}

