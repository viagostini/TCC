#include <stdexcept>
#include "../include/catch.hpp"
#include "../../generators/generators.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/NaiveAlgorithm.hpp"

TEST_CASE ("Naive algorithm", "[naive]") {
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

        NaiveAlgorithm *naive = new NaiveAlgorithm(tree);

        SECTION ("Has a query function") {
            REQUIRE(naive->query(0,0) == 0);
            REQUIRE(naive->query(1,0) == 0);
            REQUIRE(naive->query(2,0) == 0);
            REQUIRE(naive->query(2,1) == 2);
            REQUIRE(naive->query(3,0) == 0);
            REQUIRE(naive->query(3,1) == 3);
            REQUIRE(naive->query(4,0) == 0);
            REQUIRE(naive->query(4,1) == 2);
            REQUIRE(naive->query(4,2) == 4);
            REQUIRE(naive->query(5,0) == 0);
            REQUIRE(naive->query(5,1) == 2);
            REQUIRE(naive->query(5,2) == 5);
            REQUIRE(naive->query(6,0) == 0);
            REQUIRE(naive->query(6,1) == 3);
            REQUIRE(naive->query(6,2) == 6);

            SECTION ("Query function returns -1 if there is no answer")
                REQUIRE(naive->query(1, tree->size()) == -1);
            
            SECTION ("Query function throws if negative depth")
                REQUIRE_THROWS_AS(naive->query(1, -1), std::invalid_argument);

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(naive->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(naive->query(tree->size(), 0), std::invalid_argument);
            }
        }
        SECTION ("Linear Tree") {
            int n = 25;
            vector<Node*> nodes;
            build_balanced_kary_tree(n, 1, nodes);
            Tree *tree = new Tree(nodes.size(), nodes[0]);
            NaiveAlgorithm *naive = new NaiveAlgorithm(tree);

            SECTION ("Has a query function") {
                for (int i = 0; i < n; i++) {
                    for (int j = tree->depth(i); j >= 0; j--) {
                        REQUIRE(naive->query(i, j) == j);
                    }
                }

                SECTION ("Query function returns -1 if there is no answer") {
                    REQUIRE(naive->query(1, tree->size()) == -1);
                    REQUIRE(naive->query(1, tree->size()) == -1);
                }

                SECTION ("Query function throws if negative depth") {
                    REQUIRE_THROWS_AS(naive->query(1, -1), std::invalid_argument);
                }

                SECTION ("Query function throws if invalid node") {
                    REQUIRE_THROWS_AS(naive->query(-1, 0), std::invalid_argument);
                    REQUIRE_THROWS_AS(naive->query(tree->size(), 0), std::invalid_argument);
                }
            }
        }
    }

}
