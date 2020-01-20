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
}
