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
  }; // returns the element at the top --> renvoi le dernier élément de la liste
  void pop(); // removes element from the top
  void push(int elem); // puts an element on top --> insère un élément après le dernier
  // si on est arrivé à la taille maximale :
    //1. un nouveau tableau, plus grand, est crée ;
    //2. le contenu du vieux tableau est copié dans le nouveau ;
    //3. le vieux tableau est détruit.
  void clear(); // removes all elements
  int size() const{
    int cpt = 0;

  }; // number of elements currently in the stack
  int maxsize() const; //size of the internal representation
};
