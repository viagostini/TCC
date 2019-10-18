#include <stdexcept>
#include "../include/catch.hpp"
#include "../include/TestUtils.hpp"
#include "../../code/include/PreOrder.hpp"

TEST_CASE ("PreOrder", "[preorder]") {
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
        // TODO: maybe test all possible queries?
        CHECK(preorder->query(0,0) == 0);
        CHECK(preorder->query(1,0) == 0);
        CHECK(preorder->query(2,0) == 0);
        CHECK(preorder->query(2,1) == 2);
        CHECK(preorder->query(3,0) == 0);
        CHECK(preorder->query(3,1) == 3);
        CHECK(preorder->query(4,0) == 0);
        CHECK(preorder->query(4,1) == 2);
        CHECK(preorder->query(4,2) == 4);
        CHECK(preorder->query(5,0) == 0);
        CHECK(preorder->query(5,1) == 2);
        CHECK(preorder->query(5,2) == 5);
        CHECK(preorder->query(6,0) == 0);
        CHECK(preorder->query(6,1) == 3);
        CHECK(preorder->query(6,2) == 6);

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

