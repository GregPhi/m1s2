# Instructions

# Noms
Philippot Grégoire

# Description du travail:

### Description des fichiers:
	* Stack.h :
	* Stack.cpp :
	* testtp1.cpp : contient tous les test demandés dans le TP

### Commande à utiliser:
	* git clone https://gitlab-etu.fil.univ-lille1.fr/philippot/coa-tp1-stack.git
	* cd coa-tp1-stack/
	1. make : afin de compiler tous les fichiers du projet
	2. ./stack_test : afin d'éxécuter les tests de régression
	3. ./stack_main : afin d'éxécuter le main


## Classe Stack :
```cpp
...
class Stack {
    int \*s;
    int l_s;
    int max_size;
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
Stack s;
s.push(1);
REQUIRE(s.size() == 1);
REQUIRE(s.maxsize() == 1);

Stack n(s);
REQUIRE(n.size() == 1);

s.push(2);
REQUIRE(s.size() == 2);
REQUIRE(n.size() == 1);
...
```

#### Test de destruction :
```cpp
...
n.~Stack();
...
```

#### Test d'augmentation de la taille maximale de Stack :
```cpp
...
REQUIRE(s.maxsize() == 2);
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
Stack s2(10);
REQUIRE(s2.maxsize() == 10);
s2.push(1);
REQUIRE(n.size() == 1);
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
s.push(3);
s.push(4);
REQUIRE(s.size() == 4);
half(s);
REQUIRE(s.size() == 2);
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
s.push(3);
s.push(4);
REQUIRE(s.size() == 4);
Stack s4;
s4 = half_copy(s);
REQUIRE(s4.size() == 2);
REQUIRE(s.size() == 4);
...
```
