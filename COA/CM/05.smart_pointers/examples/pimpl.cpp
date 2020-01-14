#include "pimpl.h"

class MyClassImpl {
    int x;
public:
    MyClassImpl() : x(0) {}
    void function() { x++; }
};



MyClass::MyClass() : pimpl(new MyClassImpl())
{
}

MyClass::~MyClass() 
{
    delete pimpl;
}

void MyClass::function() 
{
    return pimpl->function();
}

