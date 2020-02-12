#include "Stack.h"
<<<<<<< HEAD
#include "Hanoi.h"

int main(){
  Stack src, dest, aux;
  int d = 8;
  for(int i = 0; i < d; i++){
    src.push(d-i);
  }
  solve(d,src,dest,aux);
=======
#include <iostream>

int main(){
  Stack tower1(8);
  Stack tower2;
  Stack tower3;

  for(int i = 1; i <= 8; i++){
    tower1.push(i);
  }

  
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
}
