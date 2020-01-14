#include <utility>
#include <memory>
#include <iostream>

using namespace std;

int main()
{
    unique_ptr<int> p = make_unique<int>(5);
    unique_ptr<int> q;

    cout << "p is " << p.get() << endl;
    cout << "q is " << q.get() << endl;
        
    q = std::move(p);

    cout << "p is " << p.get() << endl;
    cout << "q is " << q.get() << endl;

    //cout << "q is now = " << *q << endl;
}
