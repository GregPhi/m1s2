#include "Stack.h"

#include <iostream>

using namespace std;

int main()
{
    Stack s;

    s.push(9);
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;

    // etc.
}

