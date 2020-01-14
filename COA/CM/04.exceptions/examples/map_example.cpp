#include <map>
#include <string>
#include <iostream>

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

template<class T, class Q>
ostream &operator<<(ostream &os, std::pair<T, Q> p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

int main()
{
    map<string, int> age; 
    
    age["Peppe"] = 40;
    age["Roberto"] = 25;
    age["Giovanna"] = 30;

    pair<string, int> elem = {"Pippo", 32}; 
    
    cout << elem.first << " = " << elem.second << endl;
    
    age.insert(elem);
    
    map<string, int>::iterator i;
    for (i = age.begin(); i != age.end(); i++) 
        cout << i->first << " = " << i->second << endl;
    
    cout << age["Roberto"] << endl;
    cout << age["Elena"] << endl;
    
    i = age.find("Roberto");
    if (i != age.end()) 
        cout << "Roberto = " << i->second << endl;
    else cout << "Not found!" << endl;
    
    print(age.begin(), age.end());

    map<double, string> ex;
    ex[2.0] = "abc";
    ex[3.14] = "pi";
    
    print(ex.begin(), ex.end());
}
