#include <iostream>
#include "stack.hpp"

using namespace std;

Stack::Elem::Elem(int d, Elem *n)
{
  data_ = d;
  next_ = n;
}

Stack::Stack()
{
  head_ = 0;
  size_ = 0;
}

Stack::~Stack()
{
  // delete all elements!
  while (head_ != 0) {
    Elem *temp = head_;
    head_ = temp->next_;
    delete temp;
  }
}

void Stack::push(int a)
{
  head_ = new Elem(a, head_);
  size_ ++;
}

int Stack::pop()
{
  if (head_ == 0) {
    cerr << "Empty Stack!\n";
    exit(-1);
  }

  Elem *temp = head_;
  head_ = temp->next_;
  int data = temp->data_;
  delete temp;
  size_ --;
  return data;
}

int Stack::size()
{
  return size_;
}
