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


int main()
{
    weak_ptr<MyClass> w;
    {
	cout << "Inside the block" << endl;
	auto p = make_shared<MyClass>(1); 

	weak_ptr<MyClass> q = p;

	cout << "shared --> " << p->get() << endl;

	auto sq = q.lock();

	if (sq) cout << "weak q --> " << sq->get() << endl;
	else cout << "weak q is invalid" << endl;
	
	w = q;
	auto sw = w.lock();
	if (sw) cout << "weak w --> " << sw->get() << endl;
	else cout << "weak w is invalid" << endl;
    }
    cout << "Outside the block" << endl;
    auto sw = w.lock();
    if (sw) cout << "weak w --> " << sw->get() << endl;
    else cout << "weak w is invalid" << endl;
}
