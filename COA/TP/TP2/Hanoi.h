<<<<<<< HEAD
#include "Stack.h"

void solve(int nb, Stack &src, Stack &dest, Stack &aux);

void displayHanoi(Stack const &src, Stack const &dest, Stack const &aux);

void moveOne(Stack &src, Stack &dest);
=======
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
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
