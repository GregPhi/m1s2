// This is not the main
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Test the copy's stack", "[stack]")
{
    Stack s;
    s.push(1);
    REQUIRE(s.size() == 1);

    Stack n(s);
    REQUIRE(n.size() == 1);

    s.push(2);

    REQUIRE(s.size() == 2);
    REQUIRE(n.size() == 1);
}
