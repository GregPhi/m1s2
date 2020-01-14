#include <functional>
#include <iostream>

struct Foo {
    void print_sum(int n1, int n2)
        {
            std::cout << n1+n2 << '\n';
        }
    int data = 10;
};


int main()
{
    using namespace std::placeholders;
    
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
    f3(5);
    
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(foo) << '\n';
}
