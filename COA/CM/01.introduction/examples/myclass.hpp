#include <iostream>
using namespace std;

class MyClass {
    int a;
public:
    MyClass(int i);
    MyClass(const MyClass &r);
    void fun(int y);
    int get() const;
};