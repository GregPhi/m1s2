#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Test operator", "[stack]"){
  std::cout << "Operator : " << '\n';
  std::cout << "- &operator= " << '\n';
  Stack s1;
  s1.push(1);
  Stack s2;
  s2.push(1);
  std::cout << "- operator== " << '\n';
  REQUIRE(s1 == s2);

}
