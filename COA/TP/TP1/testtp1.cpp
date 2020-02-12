#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Test stack : TP 1", "[stack]")
{
  std::cout << "Test fonctions Stack" << '\n';
  Stack s;
  REQUIRE(s.isEmpty() == true);
  REQUIRE_THROWS(s.top());
  REQUIRE_NOTHROW(s.pop());
  s.push(1);
  REQUIRE(s.top() == 1);
  REQUIRE(s.maxsize() == 1);
  s.push(2);
  REQUIRE(s.size() == 2);
  REQUIRE(s.maxsize() == 2);
  s.pop();
  REQUIRE(s.top() == 1);
  REQUIRE(s.isEmpty() == false);
  s.clear();
  REQUIRE(s.isEmpty() == true);

  s.~Stack();
}
