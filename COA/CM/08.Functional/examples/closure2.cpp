#include <iostream>

using namespace std;

auto create_fun(int x)
{
    return [x] (int y) { return x + y; };
}

int main()
{
    auto f1 = create_fun(5);
    auto f2 = create_fun(7);

    cout << f1(5) << endl;
    cout << f2(5) << endl;

    return 0;
}
