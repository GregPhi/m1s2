<<<<<<< HEAD
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
=======
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Hanoi.h"

Hanoi::Hanoi(){
    tower = new Stack[];
    capa = 0;
}

Hanoi::Hanoi(int c){
    capa = c;
    tower = new Stack[3];
    for(int i = capa; i > 0; i--){
      tower[i] = new Stack(capa);
    }
    for(int i = capa; i > 0; i--){
      tower[0].push(i);
    }
}

Hanoi::Hanoi(const Stack &cpy){
    tower = cpy.tower;
    capa = cpy.capa;
}

Hanoi::~Hanoi(){
    delete [] tower;
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
}
