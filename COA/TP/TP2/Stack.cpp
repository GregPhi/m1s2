#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Stack.h"

/**
   Complete the member functions below
 */

Stack::Stack(){
<<<<<<< HEAD
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
   }
   else{
     return s[l_s];
   }
}

void Stack::pop(){
 if(!isEmpty()){
   l_s--;
 }
}

void Stack::push(int elem){
 l_s++;
 if((l_s+1)>=max_size){
   int *temp;
   max_size++;
   temp = new int[max_size];
   for(int i = 0; i < size(); i++){
     temp[i] = s[i];
   }
   delete [] s;
   temp[l_s] = elem;
   s = new int[max_size];
   s = temp;
 }
 else{
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
 int *temp = new int[max_size];
 for(int i = 0; i < max_size; i++){
   temp[i] = s[i];
 }
 delete [] s;
 s = new int[max_size];
 s = temp;
 delete [] temp;
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

Stack& Stack::operator=(const Stack &other){
  l_s = other.l_s;
  max_size = other.max_size;
  delete [] s;
  s = new int[max_size];
  s = other.s;
  return *this;
=======
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
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
}

bool Stack::operator==(const Stack &other) const{
  Stack cpy_other(other);
<<<<<<< HEAD
  int *cpy_s = new int[max_size];
  cpy_s = s;
  if(cpy_other.maxsize() != maxsize() && cpy_other.size() != size()){
    return false;
  }
  for(int j = size()-1; j >= 0; j--){
=======
  int *cpy_s = s;
  int i = (maxsize() > cpy_other.maxsize()) ? maxsize() : cpy_other.maxsize();
  if(cpy_other.size() != size()){
    return false;
  }
  for(int j = i-1; j >= 0; j--){
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
    if(cpy_other.top() != cpy_s[j]){
      return false;
    }
    cpy_other.pop();
  }
<<<<<<< HEAD
  return true;
}

Stack& Stack::operator+=(const Stack &other){
  Stack cpy(other);
  while(!cpy.isEmpty()){
    push(cpy.top());
    cpy.pop();
  }
  return *this;
}

Stack& Stack::operator+=(int elem){
  if(top() > elem){
    push(elem);
  }else{
    throw IncorectPush(top(),elem);
  }
  return *this;
}

Stack operator+(const Stack &s1, const Stack &s2){
  Stack cpy(s1);
  cpy+=s2;
  return cpy;
=======
  cpy_other.~Stack();
  delete [] cpy_s;
  return true;
}



Stack operator+(const Stack &s1, const Stack &s2){
  Stack s;
  return s;
  //return s1+=s2;
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
}

std::ostream& operator<<(std::ostream &os, const Stack &s){
  Stack cpy(s);
<<<<<<< HEAD
  os << "[";
  while(!cpy.isEmpty()){
    os << cpy.top() << " ";
    cpy.pop();
  }
  os << "]";
  return os;
}
=======
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
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
