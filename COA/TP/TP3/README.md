# Instructions

Le but de ce TP est de 1) s'entraîner avec le concept d'héritage
public, et 2) utiliser une bibliothèque C++ existante. Il faut
écrire un programme pour créer, dessiner et manipuler des formes
géométriques sur l'écran.

## La bibliothéque CImg

Pour visualiser les formes, on utilise la librairie /CImg/
[[http://cimg.eu/]]. La librairie est composée d'un seul fichier
CImg.h qu'il faut inclure dans notre programme. Un exemple de
programme est fourni dans le fichier
[example_cimg.cpp](example_cimg.cpp).

La documentation de la librairie est fourni dans
[docs/CImg_reference.pdf](docs/CImg_reference.pdf).


# Noms

Philippot Grégoire

# Description du travail:

* créer des formes (rectangle, cercle et triangle) grâce à la bibliothèque CImg
* permettre à un utilisateur de créer des formes grâce à son clavier et à l'endroit où se situe sa souris

## Question 1 : Les formes

La fonction devant fortement être virtual est 'draw'.

La fonction draw doit être défini 'virtual', car elle aura une action différente selon la forme qu'on souhaite dessiner.
```cpp
...
virtual void draw() =0;
...
```

## Question 2 : Mémoriser les formes

Commandes à éxécuter :
* $ make
* $ ./shape_main

## Question 3 : Sélectionner une forme

La fonction is_inside() doit être défini comme 'virtual' dans la classe Shape, car afin de savoir si un point est dans une forme, on effectuera des calculs différents.
```cpp
...
virtual bool is_inside(int x, int y)=0;
...
```

Les fonctions isSelected et select ne doivent pas être défini comme 'virtual' dans la classe Shape, car quelque soit la forme on effectue la même action.
```cpp
...
bool isSelected();
void select(bool value);
...
```

## Question 4 : Créer, deplacer, effacer des formes

```cpp
...
bool keyT = main_disp.is_key(cimg::keyT); // draw triangle
bool keyR = main_disp.is_key(cimg::keyR); // draw rectangle
bool keyC = main_disp.is_key(cimg::keyC); // draw cercle
...
```
Puis on teste si une des touches du clavier {t,r,c} a été actionnée.


## Question 5 : Regrouper des formes

```cpp
...
class ShapeGroup : public Shape{
  std::vector<Shape *> shapes;
  public:
    ShapeGroup();
    virtual void draw(CImg<unsigned char>* img);
    virtual bool is_inside(int x, int y);
    void move(int px, int py);
};
...
```


##### CODE TESTE
-----------

vector<Shape *> shapes;

x = main_disp.mouse_x();    // get the x position of the mouse, relative to the window
y = main_disp.mouse_y();    // get the x position of the mouse, relative to the window

bool click = main_disp.button();

bool keyT = main_disp.is_key(cimg::keyT); // draw triangle
bool keyR = main_disp.is_key(cimg::keyR); // draw rectangle
bool keyC = main_disp.is_key(cimg::keyC); // draw cercle
bool keyD = main_disp.is_key(cimg::keyD); // delete shapes
bool keyM = main_disp.is_key(cimg::keyM); // mouse

if(keyT){
  Shape *t = new Triangle(0,0,5,5,6,6,green);
  t->draw(img);
  shapes.push_back(t);
}
if(keyR){
  Shape *r = new Rectangle(10,10,50,75,green);
  shapes.push_back(r);
}
if(keyC){
  Shape *c = new Circle(0,0,15,green);
  shapes.push_back(c);
}

if(keyD){
  for(int i = 0; i < shapes.size(); i++){
    if(shapes.at(i)->isSelected()){
      delete shapes.at(i);
      shapes.erase(shapes.begin()+i);
    }
  }
}

for(Shape *s : shapes){
  if(s->isSelected()){
    if(keyM){
      s->move(x,y);
    }
  }
  if(click && s->is_inside(x,y)){
    s->select(!s->isSelected());
  }
  s->draw(img);
}
