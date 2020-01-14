#include <vector>
#include <iostream>
#include <utility>

//#include "destroy.hpp"
#include "triangle.hpp"
#include "rect.hpp"
#include "circle.hpp"

template <class T>
class MyContainer {
    std::vector<T *> v;

    T* copy_element(const T *p) {
        T* p2 = nullptr;
        if constexpr (std::is_polymorphic<T>::value) {
                p2 = p->clone();
            } else {
            p2 = new T(*p);
        }
        return p2;
    }

public:
    MyContainer() {}

    MyContainer(const MyContainer & other) {
        for (T* p : other.v) 
            v.push_back(copy_element(p));
        
    }
    
    size_t size() const { return v.size(); }
    
    void push(const T &elem) {
        T *p = copy_element(&elem);
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

    for (size_t i=0; i<cont.size(); i++)
        cont[i].draw();

    auto copy(cont);

    for (size_t i=0; i<copy.size(); i++)
        copy[i].draw();

    cont2.push(5);
    cont2.push(7);
    
    for (size_t i=0; i<cont2.size(); i++)
        cout << cont2[i] << endl;
    
    auto copy2(cont2);

    for (size_t i=0; i<copy2.size(); i++)
        cout << copy2[i] << endl;
    
    return 0;
}
