#include <stdexcept>
#include "../include/catch.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/JumpPointers.hpp"

TEST_CASE ("Jump Pointers", "[jump]") {
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
    JumpPointerLA *jump = new JumpPointerLA(tree);

    SECTION ("Has a query function") {
        // TODO: maybe test all possible queries?
        CHECK(jump->query2(0,0) == 0);
        CHECK(jump->query2(1,0) == 0);
        CHECK(jump->query2(2,0) == 0);
        CHECK(jump->query2(2,1) == 2);
        CHECK(jump->query2(3,0) == 0);
        CHECK(jump->query2(3,1) == 3);
        CHECK(jump->query2(4,0) == 0);
        CHECK(jump->query2(4,1) == 2);
        CHECK(jump->query2(4,2) == 4);
        CHECK(jump->query2(5,0) == 0);
        CHECK(jump->query2(5,1) == 2);
        CHECK(jump->query2(5,2) == 5);
        CHECK(jump->query2(6,0) == 0);
        CHECK(jump->query2(6,1) == 3);
        CHECK(jump->query2(6,2) == 6);

        SECTION ("Query function returns -1 if there is no answer") {
            REQUIRE(jump->query2(1, tree->size()) == -1);
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
