#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "shape.hpp"

class Triangle : public Shape {
    int aa, bb;
public:
    Triangle(int x, int y, int a, int b);
    virtual void draw();
    virtual void resize(int scale);
    virtual void rotate(int degree);
    CLONABLE(Triangle);
};

#endif
