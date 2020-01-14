#include "stack_template.hpp"
#include <iostream>

using namespace std;

class MyClass {
    static int count;
    int data;
    friend ostream&  operator<<(ostream &os, const MyClass &elem);
public:
    MyClass(int d) : data(d) { count++; }
    MyClass(const MyClass &other) { data = other.data; count ++; }
    ~MyClass() { count--; }

    int get() const { return data; }
    void set(int d) { data = d; }

    static int howMany() { return count; }
};

int MyClass::count = 0;

ostream &operator<<(ostream &os, const MyClass &elem)
{
    os << '#' << elem.data << '#';
    return os;
}


int main()
{
    Stack<int> s1;

    s1.push(5);
    cout << s1.top() << endl;
    s1.pop();

    Stack<MyClass> s2;
    cout << "Before push, there are " << MyClass::howMany() << " objects of MyClass" << endl;
    s2.push(MyClass(10));
    cout << "After push, there are " << MyClass::howMany() << " objects of MyClass" << endl;
    
    cout << s2.top() << endl;

    cout << "Before pop, there are " << MyClass::howMany() << " objects of MyClass" << endl;
    s2.pop();
    cout << "After  pop, there are " << MyClass::howMany() << " objects of MyClass" << endl;
    
}
