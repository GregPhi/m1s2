class Stack {
  int *pile;
public:
  Stack();// default constructor, empty stack
  Stack(int taille){
    pile = new int[taille];
  };
  Stack(const Stack &s); // copy constructor
  ~Stack();// destructor
  bool isEmpty() const{
    return pile == {};
  }; //returns true if empty
  int top() throws EmptyExc const{
    if(pile == {}){
      return EmptyExc;
    }else{
      
    }
  }; // returns the element at the top
  void pop(); // removes element from the top
  void push(int elem); // puts an element on top
  void clear(); // removes all elements
  int size() const{
    int cpt = 0;

  }; // number of elements currently in the stack
  int maxsize() const; //size of the internal representation
};
