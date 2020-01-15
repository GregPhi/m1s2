#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Stack.h"

/**
   Complete the member functions below
 */

Stack::Stack(){
    max_size = 0;
    s = new int[max_size];
    l_s = -1;
}

Stack::Stack(int size){
    s = new int[size];
    l_s = -1;
    max_size = size;
}

Stack::Stack(const Stack &cpy){
    s = cpy.s;
    l_s = cpy.l_s;
    max_size = cpy.max_size;
}

Stack::~Stack(){
    delete [] s;
}

bool Stack::isEmpty() const{
    return size()==0;
}

int Stack::top() const{
    if(isEmpty()){
      throw EmptyExc();
    }else{
      return s[l_s];
    }
}

void Stack::pop(){
    if(!isEmpty()){
      l_s--;
    }
}

void Stack::push(int elem){
    if((l_s+1)==max_size){
      int m = max_size+1;
      int *temp = new int[m];
      for(int i = 0; i < max_size; i++){
        temp[i] = s[i];
      }
      max_size = m;
      s = temp;
      push(elem);
    }else{
      l_s++;
      s[l_s] = elem;
    }
}

void Stack::clear(){
    delete [] s;
    l_s = -1;
    s = new int[max_size];
}

int Stack::size() const{
    return l_s+1;
}

int Stack::maxsize() const{
    return max_size;
}

void Stack::reduce(){
  max_size = l_s+1;
}

void Stack::half(const Stack &ha){
    std::ostringstream cout;
    int t = ha.l_s+1;
    int h = t/2;
    for(int i = 0; i < h; i++){
      cout << "pop half" << ha.pop();
    }
}

Stack Stack::half_copy(const Stack &ha){
    Stack cpy(ha);
    half(cpy);
    return cpy;
}
