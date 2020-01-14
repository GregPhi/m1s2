#include <iostream>

// Forward declaration 
// I just declare the existence of a class, without declaring its interface
// in the following I can define pointer to this type, but I cannot use any 
// other feature 
class MyClassImpl;

class MyClass {
  // all data members are inside the implementation
  MyClassImpl *pimpl;
 public:
  
  // Constructor
  MyClass();

  // Interface
  void function();

  // does not need to be declared virtual 
  // (unless MyClass is a base class of a hierarchy,
  // and I want to delate objects of type MyClass 
  // polymorphically. 
  ~MyClass();
};
