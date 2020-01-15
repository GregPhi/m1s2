#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <sstream>
#include <exception>

class EmptyExc : public std::exception{
  private:
    std::string msg;
  public:
    EmptyExc(){
      std::ostringstream oss;
      oss << "The stack is empty";
      this->msg = oss.str();
    }
    virtual ~EmptyExc() throw(){}
    virtual const char *what() const throw(){
      return this->msg.c_str();
    }
};

class Stack {
    int *s; // table of int
    int l_s; // last infex of tabke
    int max_size; // max size of table
 public:
    Stack();               // default constructor, empty stack
    Stack(int size);       // create a stack with a definize size
    Stack(const Stack &cpy); // copy constructor
    ~Stack();              // destructor

    bool isEmpty() const;  // returns true if empty
    int top() const;       // returns the element at the top
    void pop();            // removes element from the top
    void push(int elem);    // puts an element on top
    void clear();          // removes all elements
    int size() const;      // number of elements currently in the stack
    int maxsize() const;   // size of the internal representation
    void reduce();         // set the max size to the real size of table
    void half(const Stack &ha); //
    Stack half_copy(const Stack &ha); //
};

#endif
