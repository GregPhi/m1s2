#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stack.h"

TEST_CASE("Test operator", "[stack]"){
<<<<<<< HEAD
  Stack s1;
  s1.push(1);
  Stack s2 = s1;
  REQUIRE(s1.size() == s2.size());
  REQUIRE(s1 == s2);
  s1.push(2);
  Stack s666;
  s666.push(9);
  s666+=s1;
  REQUIRE(s1.size()+1 == s666.size());
  s1+=3;
  REQUIRE(s1.size()==3);
  REQUIRE_THROWS(s1+=0);
  Stack s3;
  std::stringstream empty,OneEle,TwoElem;
  empty<<s3;
  REQUIRE(empty.str()=="[]");
  OneEle<<s2;
  REQUIRE(empty.str()=="[1 ]");
  TwoElem<<s1;
  REQUIRE(empty.str()=="[1 2 3 ]");
=======
  std::cout << "Operator : " << '\n';
  std::cout << "- &operator= " << '\n';
  Stack s1;
  s1.push(1);
  Stack s2;
  s2.push(1);
  std::cout << "- operator== " << '\n';
  REQUIRE(s1 == s2);

>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
}
