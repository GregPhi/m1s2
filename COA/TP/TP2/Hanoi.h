#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <sstream>
#include <exception>
#include "Stack.h"

class Hanoi{
  Stack *tower;
  int capa;
  public:
    Hanoi();
    Hanoi(int c);
    Hanoi(const Hanoi &cpy);
    ~Hanoi();
}
