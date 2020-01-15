#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Create a Stack and insert an element", "[stack]")
{
    Stack s;
    s.push(1);
    REQUIRE(s.size() == 1);
    REQUIRE(s.top()==1);
    s.push(2);
    REQUIRE(s.size() == 2);
    REQUIRE(s.top()==2);
    s.pop();
    REQUIRE(s.size() == 1);
    REQUIRE(s.isEmpty() == false);
}
