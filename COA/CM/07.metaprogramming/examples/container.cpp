#include <vector>
#include <iostream>
#include <utility>

#include "destroy.hpp"
#include "triangle.hpp"
#include "rect.hpp"
#include "circle.hpp"


template<bool flag>
class Bool2Type {
    enum { value = flag };
};


template<class T>
class MyContainer {
    std::vector<T *> v;

    // template<bool isPolymorphic>
    // T* copy_element(T *p) {
    //     return new T(*p);
    // }

    // template<>
    // T* copy_element<true>(T *p) {
    //     return p->clone();
    // }

    T* copy_element(const T *p, Bool2Type<false>) {
        return new T(*p);
    }

    T* copy_element(const T *p, Bool2Type<true>) {
        return p->clone();
    }
    
public:
    MyContainer() {}

    MyContainer(const MyContainer &other) {
        for (int i=0; i<other.v.size(); ++i) 
            v.push_back(copy_element(other.v[i],
                                     Bool2Type<std::is_polymorphic<T>::value>()));
    }

    size_t size() const { return v.size(); }
    
    void push(const T &elem) {
        T *p = copy_element(&elem, Bool2Type<std::is_polymorphic<T>::value>());
        v.push_back(p);
    }
    
    T &operator[](int index) { return *v[index]; }

    ~MyContainer() {
        destroy(std::begin(v), std::end(v));
    }
};


using namespace std;

int main()
{
    MyContainer<Shape> cont;
    MyContainer<int> cont2;
    
    Triangle t(0, 1, 2, 3);
    Rect r(4, 5, 6, 7);
    Circle c(0, 0, 10);

    cont.push(t);
    cont.push(r);
    cont.push(c);

!    for (int i=0; i<cont.size(); i++)
        cont[i].draw();

    auto copy(cont);

    for (int i=0; i<copy.size(); i++)
        copy[i].draw();

    cont2.push(5);
    cont2.push(7);
    
    for (int i=0; i<cont2.size(); i++)
        cout << cont2[i] << endl;

    auto copy2(cont2);

    for (int i=0; i<copy2.size(); i++)
        cout << copy2[i] << endl;
    
    return 0;
}
