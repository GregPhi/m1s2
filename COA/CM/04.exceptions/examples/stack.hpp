class Stack {
  class Elem {
  public:
    int data_;
    Elem *next_;
    Elem(int d, Elem *n);
  };

 public:

  Stack();
  ~Stack();

  void push(int a);
  int pop();
  int size();

 private:
  Elem *head_;
  int size_;
};
