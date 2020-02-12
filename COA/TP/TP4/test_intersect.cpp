#include "catch.hpp"
#include "myclass.hpp"
#include "set_operations.hpp"

using namespace std;

TEST_CASE("set_union","[question 2.1]")
{
  const vector<int> v1 = { 1, 2, 3, 4 };
  const vector<int> v2 = { 3, 4, 5, 6 };
  vector<int> v3;

  v3 = set_union(v1,v2);
  REQUIRE(v3.size() == 1);
  REQUIRE(v3[0] == 3);
}

TEST_CASE("intersection of integers", "[template]")
{
    vector<int> v1 = { 1, 2, 3, 4 };
    vector<int> v2 = { 3, 4, 5, 6 };
    vector<int> v3;

    set_intersect(begin(v1), end(v1), begin(v2), end(v2),
                  back_inserter(v3));
    REQUIRE(v3.size() == 1);
    REQUIRE(v3[0] == 3);
}
