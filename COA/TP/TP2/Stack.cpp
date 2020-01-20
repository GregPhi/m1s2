#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
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
    max_size = size;
    s = new int[size];
    l_s = -1;
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

bool Stack::operator==(const Stack &other) const{
  Stack cpy_other(other);
  int *cpy_s = s;
  int i = (maxsize() > cpy_other.maxsize()) ? maxsize() : cpy_other.maxsize();
  if(cpy_other.size() != size()){
    return false;
  }
  for(int j = i-1; j >= 0; j--){
    if(cpy_other.top() != cpy_s[j]){
      return false;
    }
    cpy_other.pop();
  }
  cpy_other.~Stack();
  delete [] cpy_s;
  return true;
}



Stack operator+(const Stack &s1, const Stack &s2){
  Stack s;
  return s;
  //return s1+=s2;
}

std::ostream& operator<<(std::ostream &os, const Stack &s){
  Stack cpy(s);
  cpy.display(os);
  return os;
}

void Stack::display(std::ostream &os){
  os << " stack : ";
  for(int i = size(); i >= 0; i--){
    os << top();
    pop();
  }
  os << "size of stack : " << size() << "max size of stack : " << maxsize() << "\n";
}



void half(Stack &ha){
    int l = ha.size();
    for (int i = 0; i < l/2; i++) {
      ha.pop();
    }
}

Stack half_copy(const Stack &ha){
    Stack cpy(ha);
    half(cpy);
    return cpy;
}
