#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Question 1.1", "[stack]")
{
  std::cout << "Test cppy" << '\n';
  Stack s;
  s.push(1);
  REQUIRE(s.size() == 1);
  REQUIRE(s.maxsize() == 1);

  Stack n(s);
  REQUIRE(n.size() == 1);

  s.push(2);
  REQUIRE(s.size() == 2);
  REQUIRE(n.size() == 1);


  std::cout << "Test destructeur" << '\n';
  n.~Stack();

  std::cout << "Test agrandissement de la taille" << '\n';
  REQUIRE(s.maxsize() == 2);

  std::cout << "Test reduce" << '\n';
  Stack s2(10);
  REQUIRE(s2.maxsize() == 10);
  s2.push(1);
  REQUIRE(n.size() == 1);
  s2.reduce();
  REQUIRE(s2.maxsize() == 1);

  std::cout << "Test half" << '\n';
  s.push(3);
  s.push(4);
  REQUIRE(s.size() == 4);
  half(s);
  REQUIRE(s.size() == 2);

  std::cout << "Test half_copy" << '\n';
  s.push(3);
  s.push(4);
  REQUIRE(s.size() == 4);
  Stack s4;
  s4 = half_copy(s);
  REQUIRE(s4.size() == 2);
  REQUIRE(s.size() == 4);
}
