#include <iostream>
#include <memory>

using namespace std;

class YourClass; 

class MyClass {
    int x;
    shared_ptr<YourClass> pt;
public:
    MyClass(int i) : x(i) {
	cout << "Constructor of MyClass with " << x << endl;
    }
    void link(shared_ptr<YourClass> c) {
	pt = c;
    }
    int get() const { return x; }
    ~MyClass() {
	cout << "Destructor of MyClass with " << x << endl;
    }
};


class YourClass {
    int x;
    shared_ptr<MyClass> pt;
public:
    YourClass(int i) : x(i) {
	cout << "Constructor of YourClass with " << x << endl;
    }
    void link(shared_ptr<MyClass> c) {
	pt = c;
    }
    int get() const { return x; }
    ~YourClass() {
	cout << "Destructor of MyClass with " << x << endl;
    }
};

int main() 
{
    cout << "Before Creation" << endl;
    { 
	shared_ptr<MyClass>   p1 = make_shared<MyClass>(0);   //  p1->0
	shared_ptr<YourClass> p2 = make_shared<YourClass>(1); // p2->1

	p1->link(p2);                                     // p1 and 1 -> 0 
	p2->link(p1);                                     // p2 and 0 -> 1
    }
    cout << "After Creation" << endl;
}
