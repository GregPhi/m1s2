#include <memory>

#include "myclass.hpp"

using namespace std;

int main()
{
    MyClass x(5);
    //MyClass vec[5];

    // memory allocation
    MyClass *vec = static_cast<MyClass *>(operator new(sizeof(MyClass) * 5));
    // construction
    for (int i=0; i<5; i++) {
        new (vec + i) MyClass(i);
    }

    for (MyClass *p=vec; p!=vec+5; p++)
        cout << *p << endl;
}
