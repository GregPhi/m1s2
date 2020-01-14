#include <iostream>
#include <memory>

using namespace std;

class MyClass {
    int x;
public:
    MyClass(int i) : x(i) {
	cout << "Constructor of MyClass with " << x << endl;
    }
    int get() const { return x; }
    ~MyClass() {
	cout << "Destructor of MyClass with " << x << endl;
    }
};

shared_ptr<MyClass> pg;  // initialized to nothing

shared_ptr<MyClass> create(int i, bool flag) 
{
    auto q = make_shared<MyClass>(i);

    if (!flag) throw string("Exception is raised!");
    
    return q;
}

int main() 
{
    shared_ptr<MyClass> p1 = make_shared<MyClass>(0);
    pg = p1;

    {
	auto p2 = make_shared<MyClass>(1);
	cout << "pg --> " << pg->get() << endl;
	p1 = p2;
	
	try {

	    pg = create(2, true);
	    cout << "First creation is ok" << endl;
	    pg = create(3, false);
	    cout << "Second creation is ok" << endl;
        
	} catch (string &err) {
	    cout << "An error occurred! " << err << endl;
	    cout << "pg --> " << pg->get() << endl;
	}
    }
    cout << "p1 --> " << p1->get() << endl;
    cout << "pg --> " << pg->get() << endl;
    
    p1.reset();
    cout << "End" << endl;
}
