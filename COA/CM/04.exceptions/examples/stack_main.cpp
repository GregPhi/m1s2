#include <iostream>
#include <cstdlib>
#include "stack.hpp"

using namespace std;

int main()
{
  Stack stack1;
  Stack stack2;

  for (int i=0; i<10; i++) {
    stack1.push(i*i);
  }
  
  int a = stack1.pop();
  int b;
  for (int i=0; i<9; i++) {
    b = stack1.pop();
    stack2.push(a - b);
    a = b;
  }

  for (int i=0; i<9; i++)
    cout << stack2.pop() << endl;
#ifndef CYGNUS
  system("pause");
#endif
}
