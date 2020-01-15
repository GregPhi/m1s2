#include "Stack.h"

#include <iostream>

using namespace std;

int main()
{
    Stack s;
    cout << "empty : " << s.isEmpty() << endl;

    s.push(9);
    cout << "empty : " << s.isEmpty() << endl;
    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;
    s.push(1);
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;

    // etc.
}
