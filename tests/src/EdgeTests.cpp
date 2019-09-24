#include "../include/catch.hpp"
#include "../../code/include/Edge.hpp"

TEST_CASE ("Edge", "[edge]") {
    int x = 4, y = 5;
    Edge edge(x, y);

    REQUIRE(edge.from == 4);
    REQUIRE(edge.to == 5);
}

