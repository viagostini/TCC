#include <stdexcept>
#include <chrono>
#include <iostream>
#include "../include/catch.hpp"
#include "../include/TestUtils.hpp"
#include "../../generators/generators.hpp"
#include "../../code/include/TableAlgorithm.hpp"

using namespace std;

TEST_CASE ("Table algorithm", "[table]") {
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
        TableAlgorithm *table = new TableAlgorithm(tree);

        SECTION("Has a query function") {
            REQUIRE(table->query(0,0) == 0);
            REQUIRE(table->query(1,0) == 0);
            REQUIRE(table->query(2,0) == 0);
            REQUIRE(table->query(2,1) == 2);
            REQUIRE(table->query(3,0) == 0);
            REQUIRE(table->query(3,1) == 3);
            REQUIRE(table->query(4,0) == 0);
            REQUIRE(table->query(4,1) == 2);
            REQUIRE(table->query(4,2) == 4);
            REQUIRE(table->query(5,0) == 0);
            REQUIRE(table->query(5,1) == 2);
            REQUIRE(table->query(5,2) == 5);
            REQUIRE(table->query(6,0) == 0);
            REQUIRE(table->query(6,1) == 3);
            REQUIRE(table->query(6,2) == 6);

            SECTION ("Query function returns -1 if there is no answer")
                REQUIRE(table->query(1, tree->size()) == -1);
            
            SECTION ("Query function throws if negative depth")
                REQUIRE_THROWS_AS(table->query(1, -1), std::invalid_argument);

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(table->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(table->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
    SECTION ("Linear Tree") {
        int n = 15;
        vector<Node*> nodes;
        build_balanced_kary_tree(n, 1, nodes);
        Tree *tree = new Tree(nodes.size(), nodes[0]);
        TableAlgorithm *table = new TableAlgorithm(tree);

        SECTION ("Has a query function") {
            for (int i = 0; i < n; i++) {
                for (int j = tree->depth(i); j >= 0; j--) {
                    REQUIRE(table->query(i, j) == j);
                }
            }

            SECTION ("Query function returns -1 if there is no answer") {
                REQUIRE(table->query(1, tree->size()) == -1);
                REQUIRE(table->query(1, tree->size()) == -1);
            }

            SECTION ("Query function throws if negative depth") {
                REQUIRE_THROWS_AS(table->query(1, -1), std::invalid_argument);
            }

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(table->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(table->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
    SECTION ("Binary Tree") {
        int n = 9;
        vector<Node*> nodes;
        build_balanced_kary_tree(n, 2, nodes);
        Tree *tree = new Tree(nodes.size(), nodes[0]);
        TableAlgorithm *table = new TableAlgorithm(tree);

        SECTION ("Has a query function") {
            REQUIRE(table->query(0, 0) == 0);
            REQUIRE(table->query(1, 0) == 0);
            REQUIRE(table->query(1, 1) == 1);
            REQUIRE(table->query(2, 0) == 0);
            REQUIRE(table->query(2, 1) == 2);
            REQUIRE(table->query(3, 0) == 0);
            REQUIRE(table->query(3, 1) == 1);
            REQUIRE(table->query(3, 2) == 3);
            REQUIRE(table->query(4, 0) == 0);
            REQUIRE(table->query(4, 1) == 1);
            REQUIRE(table->query(4, 2) == 4);
            REQUIRE(table->query(5, 0) == 0);
            REQUIRE(table->query(5, 1) == 2);
            REQUIRE(table->query(5, 2) == 5);
            REQUIRE(table->query(6, 0) == 0);
            REQUIRE(table->query(6, 1) == 2);
            REQUIRE(table->query(6, 2) == 6);
            REQUIRE(table->query(7, 0) == 0);
            REQUIRE(table->query(7, 1) == 1);
            REQUIRE(table->query(7, 2) == 3);
            REQUIRE(table->query(7, 3) == 7);
            REQUIRE(table->query(8, 0) == 0);
            REQUIRE(table->query(8, 1) == 1);
            REQUIRE(table->query(8, 2) == 3);
            REQUIRE(table->query(8, 3) == 8);

            SECTION ("Query function returns -1 if there is no answer") {
                REQUIRE(table->query(1, tree->size()) == -1);
                REQUIRE(table->query(1, tree->size()) == -1);
            }

            SECTION ("Query function throws if negative depth") {
                REQUIRE_THROWS_AS(table->query(1, -1), std::invalid_argument);
            }

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(table->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(table->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
}
