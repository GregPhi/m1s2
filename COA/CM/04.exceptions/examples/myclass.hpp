#ifndef __MYCLASS_HPP__
#define __MYCLASS_HPP__

#include <iostream>

class MyClass {
    int x;
    friend std::ostream &operator<<(std::ostream &os, const MyClass &other);   
public:
    MyClass(int x) { this->x = x; }
    MyClass() : x(0) {}

    MyClass(const MyClass &other) : x(other.x) {}

    int get() const { return x; }
    MyClass &operator=(int x) { this->x = x; return *this; }
    MyClass &operator=(const MyClass &other) { this->x = other.x; return *this; }    
};


std::ostream &operator<<(std::ostream &os, const MyClass &obj)
{
    os << "obj{ x=" << obj.x << " }";
    return os;
}

#endif
