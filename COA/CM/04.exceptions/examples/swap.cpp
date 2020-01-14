/**
   swap is already in the std library! 
   do not use "using namespace std", otherwise the two definitions
   conflict.
 */

#include <iostream>

template<class T>
void swap(T &a, T &b)
{
    T tmp(a);
    a = b;
    b = tmp;
}

class MyClass {
    int x;
public:
    MyClass(int a);
    //MyClass() : x(0) {}
    MyClass(const MyClass &t);
    MyClass & operator=(const MyClass &t);
    inline int get() const { return x; }
};

MyClass::MyClass(int a) : x(a) {}

MyClass::MyClass(const MyClass &t) : x(t.x) {}

MyClass & MyClass::operator=(const MyClass &t) 
{
    x = t.x;
    return *this;
}

int main()
{
    int x = 5, y= 8;
    swap(x, y);

    std::cout << "x = " << x << std::endl; 
    std::cout << "y = " << y << std::endl; 

    MyClass xx(5), yy(8);

    swap(xx, yy);

    std::cout << "xx = " << xx.get() << std::endl; 
    std::cout << "yy = " << yy.get() << std::endl; 
}
