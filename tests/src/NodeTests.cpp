#include "../include/catch.hpp"
#include "../../code/include/Node.hpp"

TEST_CASE ("Node Test", "[node]") {
    Node node(1);
    
    SECTION ("Node has a label")
        REQUIRE(node.label() == 1);

    SECTION ("New node has no children")
        REQUIRE(node.children().empty());

    Node another_node(2);

    SECTION ("A node can be added as another node's child") {
        node.add_child(&another_node);
        REQUIRE(node.children().size() == 1);
        REQUIRE(node.children()[0]->label() == 2);
    }
}
