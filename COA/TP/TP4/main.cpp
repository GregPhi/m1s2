#include <vector>
#include <iostream>

#include "myclass.hpp"
#include "set_operations.hpp"

using namespace std;

int main()
{
    vector<int> vec_a = {1,2,3,4};
    vector<int> vec_b = {3,4,5,6};
    vector<int> vec_c;

    set_intersect(begin(vec_a), end(vec_a),
              begin(vec_b), end(vec_b),
              back_inserter(vec_c));

    for (auto i : vec_c) cout << i << endl;
}

