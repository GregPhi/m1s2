#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

#include <vector>
#include "myclass.hpp"

using namespace std;

TEST_CASE("vector of MyClass", "[template]")
{
    vector<MyClass> vec = {1, 2, 3, 4};

    REQUIRE(vec.size() == 4);
}


