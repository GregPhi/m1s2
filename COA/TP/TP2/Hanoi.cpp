#include "Hanoi.h"
#include <iostream>

void solve(int nb, Stack &src, Stack &dest, Stack &aux){
  displayHanoi(src,dest,aux);
  if (nb == 1){
    moveOne(src, dest);
  }else{
    solve(nb-1, src, aux, dest);
    moveOne(src, dest);
    solve(nb-1, aux, dest, src);
  }
}

void moveOne(Stack &src, Stack &dest){
  dest+=src.top();
  src.pop();
}

void displayHanoi(Stack const &src, Stack const &dest, Stack const &aux){
  std::cout << "pile 0 : " << src << std::endl;
  std::cout << "pile 1 : " << dest << std::endl;
  std::cout << "pile 2 : " << aux << "\n" << std::endl;
}
