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

class IncorectPush : public std::exception{
  private:
    std::string msg;
  public:
    EmptyExc(int top, int elem){
      std::ostringstream oss;
      oss << "The element " << elem << " push on the new tower is bigger of the top of this tower " << top;
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
    Stack &operator=(const Stack &other);
    bool operator==(const Stack &other) const;
    Stack & operator+=(const Stack &other);
    Stack operator+(const Stack &s1, const Stack &s2);
    std::ostream& operator<<(std::ostream &os, const Stack &s);
    Stack &operator+=(int elem);
};

void half(Stack &ha); // keep half the elements of the table
Stack half_copy(const Stack &ha); // return a copy of a table with half the elements of ha

#endif
