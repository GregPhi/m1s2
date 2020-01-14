#include <iostream>

int global = 0;

auto create_mutable(int x)
{
    return [x, &global](int y) { global = x + y; };
}

int main()
{
    auto f3 = create_mutable(5);
    auto f4 = create_mutable(7);

    std::cout << "global = " << global << std::endl;
    f3(5);
    std::cout << "global = " << global << std::endl;
    f4(5);
    std::cout << "global = " << global << std::endl;
    
    return 0;
}
