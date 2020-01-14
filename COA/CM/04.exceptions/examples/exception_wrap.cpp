//============================================================================
// Name        : exception_wrap.cpp
// Author      : Giuseppe Lipari
// Version     :
// Copyright   : c
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

class Simple {
	int i;
public:
	Simple(int ii) : i(ii) {cout << "Simple constructor" << endl;}
	~Simple() { cout << "Simple::~Simple()" << endl;}
	int get() const { return i; }
};

class HasProblem {
	Simple *ptr;
public:
	HasProblem(int i)
	{
		ptr = new Simple(i);
		if (i==2) throw -5;
		// ptr is not deallocated when i == 2
	}

	~HasProblem()
	{
		cout << "Destructor" << endl;
		delete ptr;
	}
	int get() const { return ptr->get(); }
};

class NoProblem {
	Simple *ptr;
public:
	NoProblem(int i) : ptr(0) {                
        unique_ptr<Simple> p(new Simple(i));
        cout << "Simple content: " << p->get() << endl;

	    if (i==2) throw -5;
            // p is deallocated when i == 2
                
	    ptr = p.release();
	    cout << "Simple content: " << ptr->get() << endl;
	}
	~NoProblem() {
		cout << "Destructor" << endl;
		delete ptr;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl;
	/*try {
		HasProblem h1(2);
	} catch(int &v) {
		cout << "Exception " << v << endl;
	}*/

	try {
		NoProblem h2(2);
		cout << "Normal exit" << endl;
	} catch(int &v) {
		cout << "Exception " << v << endl;
	}
	
	return 0;
}







