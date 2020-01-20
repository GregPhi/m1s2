#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Test question", "[stack]"){
  std::cout << "Test cppy" << '\n';
  Stack s1;
  s1.push(1);
  REQUIRE(s1.size() == 1);
  REQUIRE(s1.maxsize() == 1);

  Stack n(s1);
  REQUIRE(n.size() == 1);

  s1.push(2);
  REQUIRE(s1.size() == 2);
  REQUIRE(s1.top() == 2);
  REQUIRE(n.size() == 1);

  std::cout << "Test destructeur" << '\n';
  n.~Stack();

  std::cout << "Test agrandissement de la taille" << '\n';
  REQUIRE(s1.maxsize() == 2);

  s1.~Stack();

  std::cout << "Test reduce" << '\n';
  Stack s2(10);
  REQUIRE(s2.maxsize() == 10);
  s2.push(1);
  REQUIRE(s2.size() == 1);
  s2.reduce();
  REQUIRE(s2.maxsize() == 1);

  s2.~Stack();

  std::cout << "Test half" << '\n';
  Stack s3(5);
  s3.push(1);
  s3.push(2);
  s3.push(3);
  s3.push(4);
  REQUIRE(s3.size() == 4);
  half(s3);
  REQUIRE(s3.size() == 2);

  s3.~Stack();

  std::cout << "Test half_copy" << '\n';
  Stack s4(5);
  s4.push(1);
  s4.push(2);
  s4.push(3);
  s4.push(4);
  REQUIRE(s4.size() == 4);
  Stack s4cpy;
  s4cpy = half_copy(s4);
  REQUIRE(s4cpy.size() == 2);
  REQUIRE(s4.size() == 4);

  s4.~Stack();
  s4cpy.~Stack();
}
