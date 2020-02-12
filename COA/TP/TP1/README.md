# Instructions

# Noms
Philippot Grégoire

# Description du travail:

### Description des fichiers:
	* Stack.h :
	* Stack.cpp :
	* testtp1.cpp : contient les test des functions 'isEmpty(), top(), pop(), push(), maxsize(), size()'
	* testquestion.cpp : contient les tests pour les questions 1 à 4

### Commande à utiliser:
	* git clone https://gitlab-etu.fil.univ-lille1.fr/philippot/coa-tp1-stack.git
	* cd coa-tp1-stack/
	1. make : afin de compiler tous les fichiers du projet
	2. ./stack_test : afin d'éxécuter les tests de régression
	3. ./stack_main : afin d'éxécuter le main
	4. ./stack_func : afin d'éxécuter les tests des fonctions


## Classe Stack :
```cpp
...
class Stack {
    int \*s; // pile contenant les entiers
    int l_s; // indice de l'élément en top, iniatilisé à -1
    int max_size; // taille maximale de la pile, iniatilisé à 1 pour le constructeur par défaut
 public:
    Stack();
    Stack(int size);
    Stack(const Stack &cpy);
    ~Stack();

    bool isEmpty() const;
    int top() const;
    void pop();
    void push(int elem);
    void clear();        
    int size() const;     
    int maxsize() const;   
    void reduce();        
};
...
```

## Classe EmptyExc :
```cpp
...
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
...
```

## Fonctions globales :
```cpp
...
void half(Stack &ha);
Stack half_copy(const Stack &ha);
...
```

## Question 1

Les tests s'effectuent parfaitement.

### Tests de régression :
#### Test de copie :
```cpp
...
Stack s1;
s1.push(1);
REQUIRE(s1.size() == 1);
REQUIRE(s1.maxsize() == 1);

Stack n(s1);
REQUIRE(n.size() == 1);

s1.push(2);
REQUIRE(s1.size() == 2);
REQUIRE(s1.top() == 2);
REQUIRE(n.size() == 1);
...
```

#### Test de destruction :
```cpp
...
std::cout << "Test destructeur" << '\n';
n.~Stack();
...
```

#### Test d'augmentation de la taille maximale de Stack :
```cpp
...
std::cout << "Test agrandissement de la taille" << '\n';
REQUIRE(s1.maxsize() == 2);
...
```

## Question 2

Prototype de la fonction :
```cpp
...
void reduce();
...
```

Les tests s'effectuent parfaitement.

### Tests de régression :

```cpp
...
std::cout << "Test reduce" << '\n';
Stack s2(10);
REQUIRE(s2.maxsize() == 10);
s2.push(1);
REQUIRE(s2.size() == 1);
s2.reduce();
REQUIRE(s2.maxsize() == 1);
...
```

## Question 3

Prototype de la fonction :
```cpp
...
void half(Stack &ha);
...
```

Les tests s'effectuent parfaitement.

### Tests de régression :

```cpp
...
std::cout << "Test half" << '\n';
Stack s3(5);
s3.push(1);
s3.push(2);
s3.push(3);
s3.push(4);
REQUIRE(s3.size() == 4);
half(s3);
REQUIRE(s3.size() == 2);
...
```

## Question 4

Prototype de la fonction :
```cpp
...
Stack half_copy(const Stack &ha);
...
```

Les tests s'effectuent parfaitement.

### Tests de régression :

```cpp
...
std::cout << "Test half_copy" << '\n';
Stack s4(5);
s4.push(1);
s4.push(2);
s4.push(3);
s4.push(4);
REQUIRE(s4.size() == 4);
Stack s4cpy;
s4cpy = half_copy(s4);
REQUIRE(s4cpy.size() == 2);
REQUIRE(s4.size() == 4);
...
```
