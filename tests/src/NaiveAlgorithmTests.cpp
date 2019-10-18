#include <stdexcept>
#include "../include/catch.hpp"
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
            // TODO: maybe test all possible queries?
            REQUIRE(naive->query(4,1) == 2);
            REQUIRE(naive->query(6,1) == 3);

            SECTION ("Query function returns -1 if there is no answer")
                REQUIRE(naive->query(1, tree->size()) == -1);
            
            SECTION ("Query function throws if negative depth")
                REQUIRE_THROWS_AS(naive->query(1, -1), std::invalid_argument);

            SECTION ("Query function throws if invalid node") {
                REQUIRE_THROWS_AS(naive->query(-1, 0), std::invalid_argument);
                REQUIRE_THROWS_AS(naive->query(tree->size(), 0), std::invalid_argument);
            }
        }
    }
}
