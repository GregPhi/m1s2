#include <iostream>

using namespace std;

class MyClass {
    int *array;
public:
    MyClass(int flag) {
        cout << "Constructor" << endl;
        array = new int[10];
        
        try {
            
            if (flag > 10) throw 10;
            
        } catch (...) {
            delete array;
            cout << "Array deleted!!!" << endl;
            throw;
        }
    }
    
    ~MyClass() {
        cout << "Destructor" << endl;
        delete array;
    }
};

int main()
{
    MyClass myclass(5);
    
    try {
        MyClass other(12);
        cout << "Never" << endl;
    } catch (...) {
        cout << "Exception caugth" << endl; 
    }    
}
