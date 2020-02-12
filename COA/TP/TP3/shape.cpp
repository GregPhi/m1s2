#include "CImg.h"
using namespace cimg_library;

#include "shape.h"
#include <iostream>
#include <cmath>

Shape::Shape(){
  abs = 0;
  ord = 0;
  clr = new unsigned char[3] {0,0,0};
  selectionned = false;
}

Shape::Shape(int abs, int ord, const unsigned char *clr){
  abs = abs;
  ord = ord;
  clr = clr;
  selectionned = false;
}

Shape::~Shape(){
  delete [] clr;
}

Shape::Shape(const Shape &s){
  abs = s.abs;
  ord = s.ord;
  clr = s.clr;
  selectionned = s.selectionned;
}

void Shape::move(int x, int y){
  abs = x;
  ord = y;
}

bool Shape::isSelected(){
  return selectionned;
}

void Shape::select(bool value){
  selectionned = value;
}

Rectangle::Rectangle(int x, int y, int width, int height, const unsigned char clr[]){
  abs = x;
  ord = y;
  clr = clr;
  width = width;
  height = height;
}

void Rectangle::draw(CImg<unsigned char> img){
  img.draw_rectangle(abs, ord, abs+width, ord+height, green);
  if(selectionned){
    img.draw_rectangle(abs-5, ord-5, abs+width+5, ord+height+5, red);
  }
}

bool Rectangle::is_inside(int px, int py){
  bool x = (px > abs) && (px < (abs + width));
  bool y = (py > ord) && (py < (ord + height));
  return x && y;
}

Triangle::Triangle(int x0,int y0,int x1,int y1,int x2,int y2, const unsigned char clr[]){
  abs = x0;
  ord = y0;
  clr = clr;
  x1 = x1;
  x2 = x2;
  y1 = y1;
  y2 = y2;
}

void Triangle::draw(CImg<unsigned char> img){
  img.draw_triangle(abs, ord, abs+x1, ord+y1, abs+x2, ord+y2, green);
  if(selectionned){
    img.draw_line(abs,ord,abs+x1,ord+y1, red);
    img.draw_line(abs+x1,ord+y1,abs+x2,ord+y2, red);
    img.draw_line(abs+x2,ord+y2,abs,ord, red);
  }
}

float sign (int x,int y,int x1,int y1,int x2,int y2){
  return (x-x2)*(y1-y2)-(x1-x2)*(y-y2);
}

bool Triangle::is_inside (int px,int py){
  float s1,s2,s3;
  bool neg,pos;
  s1 = sign(px,py,abs,ord,abs+x1,ord+y1);
  s2 = sign(px,py,abs+x1,ord+y1,abs+x2,ord+y2);
  s3 = sign(px,py,abs+x2,ord+y2,abs,ord);
  pos = (s1>0) || (s2>0) || (s3>0);
  neg = (s1<0) || (s2<0) || (s3<0);
  return !(pos && neg);
}

Circle::Circle(int x, int y, int radius, const unsigned char clr[]){
  abs = x;
  ord = y;
  clr = clr;
  radius = radius;
}

bool Circle::is_inside (int px,int py){
  return (((px - abs)^2+(py - ord)^2)==radius^2);
}

void Circle::draw(CImg<unsigned char> img){
  img.draw_circle(abs, ord, radius, green);
  if(selectionned){
    img.draw_circle(abs, ord, radius, red);
  }
}

void ShapeGroup::draw(CImg<unsigned char> img){
  for(Shape* s : shapes){
    s->draw(img);
  }
}

bool ShapeGroup::is_inside(int px, int py){
  for(Shape* s : shapes){
    if(s->is_inside(px,py)){
      return true;
    }
  }
  return false;
}

void ShapeGroup::move(int px, int py){
  for(Shape* s : shapes){
    s->move(px,py);
  }
}
