#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <functional>

using namespace std;

template<class Iter>
void print(Iter begin, Iter end)
{
    Iter i = begin; 
    std::cout << "{";
    if (i!=end) cout << *i;
    i++;
    for (;i!=end; i++) cout << ", " << *i;
    cout << "}" << endl;        
}

bool mycmp(int a, int b)
{
    return a>b;
}

class MyClass {
public:
    int a;
    MyClass(int x) : a(x) {}
};

ostream &operator<<(ostream &os, const MyClass &obj)
{
    os << obj.a;
    return os;
}

class Cmp {
public:
    bool operator()(const MyClass &x, const MyClass &y)
    {
        return x.a > y.a;
    }
};

class FunObj {
public:
    int sum;
    FunObj() : sum(0) {}
    void operator()(int x) { sum += x; }
};

int main() 
{
    vector<int> v = {3, 1, 25, 23, 13, 9, 4, 21};    
    list<int> l = {1, 2, 3, 4, 5};

    sort(v.begin(), v.end());
    print(v.begin(), v.end()); 
    //sort(l.begin(), l.end());   // error!

    sort(v.begin(), v.end(), mycmp);
    print(v.begin(), v.end());

    vector<MyClass> v2 = {3, 1, 25, 23, 13, 9, 4, 21};
 
    print(v2.begin(), v2.end());
    //sort(v2.begin(), v2.end());
    //print(v2.begin(), v2.end());

    Cmp cmp_obj;
    
    bool flag = cmp_obj( MyClass(4), MyClass(5) );
    cout << flag << endl;
    sort(v2.begin(), v2.end(), cmp_obj);
    print(v2.begin(), v2.end());
    
    FunObj myfun;
    
    for_each(v.begin(), v.end(), ref(myfun));    
    cout << myfun.sum << endl;    
}
