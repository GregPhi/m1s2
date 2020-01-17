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

Stack Stack::&operator=(const Stack &other){
  if(this != &other){
    if(other.size() != l_s+1){
      delete [] s;
      l_s=-1;
      max_size = 0:
      s = nullptr;
      s = new int[other.size()];
      l_s = other.size-1;
      max_size = other.size();
    }
    std::copy(other.s, other.s + other.size(), s);
  }
  return *this;
}

bool Stack::operator==(const Stack &other) const{
  Stack cpy_other(other);
  *cpy_s = s;
  int i = (size() > cpy_other.size()) ? size() : cpy_other.size();
  for(int j = l-1; j >= 0; j--){
    if(cpy_s.top() != cpy_s[j]){
      return false;
    }
    cpy_s.pop();
  }
  return true;
}

Stack & Stack::operator+=(const Stack &other){
  Stack cpy_s(other);
  Stack res(this);
  while(!cpy_s.isEmpty()){
    res.push(cpy_s.top());
    cpy_s.pop();
  }
  return res;
}

Stack Stack::operator+(const Stack &s1, const Stack &s2){
  Stack res;
  res = s1.addition(s2);
  return res;
}

Stack addition(const stack &s2){

}

std::ostream& Stack::operator<<(std::ostream &os, const Stack &s){
  s.display(os);
  return os;
}

void display(std::ostream &os) const{
  os << " stack : ";
  for(int i = 0; i < size(); i++){
    oss << s[i];
  }
  os << "size of stack : " << size() << "max size of stack : " << maxsize() << "\n";
}

Stack &operator+=(int elem){
  if(elem < top()){
    push(elem);
  }else{
    throw IncorectPush(top(),elem);
  }
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
