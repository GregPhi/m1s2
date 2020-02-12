#include "Stack.h"
#include "Hanoi.h"

int main(){
  Stack src, dest, aux;
  int d = 8;
  for(int i = 0; i < d; i++){
    src.push(d-i);
  }
  solve(d,src,dest,aux);
}
