#include <stdexcept>
#include "../include/catch.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/JumpPointers.hpp"

TEST_CASE ("Jump Pointers", "[jump]") {
    struct DefaultTree default_tree;
    Tree *tree = new Tree(default_tree.size, default_tree.edges);
    JumpPointerLA *jump = new JumpPointerLA(tree);

    SECTION ("Has a query function") {
        // TODO: maybe test all possible queries?
        REQUIRE(jump->query1(4,1) == 2);
        REQUIRE(jump->query1(6,1) == 3);
        REQUIRE(jump->query2(4,1) == 2);
        REQUIRE(jump->query2(6,1) == 3);

        SECTION ("Query function returns -1 if there is no answer") {
            REQUIRE(jump->query1(1, tree->size()) == -1);
            REQUIRE(jump->query2(1, tree->size()) == -1);
        }

        SECTION ("Query function throws if negative depth") {
            REQUIRE_THROWS_AS(jump->query1(1, -1), std::invalid_argument);
            REQUIRE_THROWS_AS(jump->query2(1, -1), std::invalid_argument);
        }

        SECTION ("Query function throws if invalid node") {
            REQUIRE_THROWS_AS(jump->query1(-1, 0), std::invalid_argument);
            REQUIRE_THROWS_AS(jump->query1(tree->size(), 0), std::invalid_argument);
            REQUIRE_THROWS_AS(jump->query2(-1, 0), std::invalid_argument);
            REQUIRE_THROWS_AS(jump->query2(tree->size(), 0), std::invalid_argument);
        }
    }
}
