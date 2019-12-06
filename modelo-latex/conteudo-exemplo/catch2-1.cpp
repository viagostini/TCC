#include "../include/catch.hpp"
#include "../../generators/generators.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/TableAlgorithm.hpp"

TEST_CASE ("Table algorithm", "[table]") {
    SECTION ("Binary Tree") {
        int n = 2178;
        vector<Node*> nodes;
        build_balanced_kary_tree(n, 2, nodes);
        Tree *tree = new Tree(nodes.size(), nodes[0]);
        TableAlgorithm *table = new TableAlgorithm(tree);

        SECTION ("Has a query function") {
            for (int node = 0; node < n; node++) {
                for (int depth = 0; depth <= tree->depth(node); depth++) {
                    REQUIRE(table->query(node, depth) == naive_check(tree, node, depth));
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
}