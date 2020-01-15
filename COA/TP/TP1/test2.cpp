// This is not the main
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Pop an element from an empty stack", "[stack]")
{
    Stack s;
    s.push(1);
    REQUIRE(s.size() == 1);
    s.pop();
    REQUIRE_THROWS(s.top());
    REQUIRE_NOTHROW(s.pop());
}
