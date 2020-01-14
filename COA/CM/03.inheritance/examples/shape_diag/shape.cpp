#include "shape.hpp"
#include <iostream>

using namespace std;

Shape::Shape(int x,int y) : xx(x), yy(y) {}

void Shape::move(int x, int y)
{
  xx += x; yy += y;
  cout << "Shape::move called:\n";
  PR(xx); PR(yy);
}

// first solution
double Shape::diagonal() const
{
  cout << "ERROR! diagonal() called on a Shape object\n";
  return 0;
}
