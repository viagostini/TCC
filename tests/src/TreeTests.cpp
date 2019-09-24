#include <stdexcept>
#include "../../code/include/Tree.hpp"
#include "../include/catch.hpp"
#include "../include/TestUtils.hpp"

TEST_CASE ("Tree", "[tree]") {
    SECTION ("Default tree") {
        struct DefaultTree default_tree;
        Tree *tree = new Tree(default_tree.size, default_tree.edges);

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

        SECTION ("Tree has a proper DFS order") {
            vector<int> dfs = {0, 1, 2, 4, 5, 3, 6};
            vector<int> out = tree->dfs();
            for (int i = 0; i < out.size(); i++)
                REQUIRE(dfs[i] == out[i]);
        }
    }
}
