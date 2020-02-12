#include "CImg.h"
using namespace cimg_library;
#include <iostream>
#include <sstream>
#include <vector>

#ifndef __STACK_H__
#define __STACK_H__

const unsigned char
    red[]   = { 255,0,0 },
    green[] = { 0,255,0 },
    blue [] = { 0,0,255 },
    black[] = { 0,0,0 };

class EmptyExc {};

class Shape{
protected:
  int abs,ord;
  unsigned char *clr;
  bool selectionned;
public:
  Shape();
  Shape(int abs, int ord, const unsigned char clr[]);
  ~Shape();
  Shape(const Shape &s);

  void move(int x, int y);
  virtual void draw(CImg<unsigned char> img) =0;
  virtual bool is_inside(int x, int y)=0;
  bool isSelected();
  void select(bool value);
};

class Rectangle: public Shape{
  int width, height;
public:
  Rectangle(int x, int y, int width, int height, const unsigned char clr[]);
  virtual void draw(CImg<unsigned char> img);
  virtual bool is_inside(int x, int y);
};


class Circle: public Shape{
  int radius;
public:
  Circle(int x, int y, int radius,const unsigned char clr[]);
  virtual void draw(CImg<unsigned char> img);
  virtual bool is_inside(int x, int y);
};

class Triangle: public Shape{
  int x1,x2,y1,y2;
public:
  Triangle(int x0,int y0,int x1,int y1,int x2,int y2, const unsigned char clr[]);
  virtual void draw(CImg<unsigned char> img);
  virtual bool is_inside(int x, int y);
};

class ShapeGroup : public Shape{
  std::vector<Shape *> shapes;
  public:
    ShapeGroup();
    virtual void draw(CImg<unsigned char> img);
    virtual bool is_inside(int x, int y);
    void move(int px, int py);
};

#endif
