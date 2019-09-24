#include <stdexcept>
#include "../include/catch.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/TableAlgorithm.hpp"

TEST_CASE ("Table algorithm", "[table]") {
    SECTION ("Default tree") {
        struct DefaultTree default_tree;
        Tree *tree = new Tree(default_tree.size, default_tree.edges);
        TableAlgorithm *table = new TableAlgorithm(tree);

        SECTION("Has a query function") {
            // TODO: maybe test all possible queries?
            REQUIRE(table->query(4,1) == 2);
            REQUIRE(table->query(6,1) == 3);

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
}
