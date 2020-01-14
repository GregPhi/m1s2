#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

using namespace std;

std::recursive_mutex m;

int global = 0;

int recursive_function(int x)
{
    if (x == 0) {
        std::unique_lock<std::recursive_mutex> l(m);
        std::cout << "End of recursion" << std::endl;
        return x;
    }
    else {
        std::unique_lock<std::recursive_mutex> l(m);
        cout << "This is recursive_function(" << x << ");" << endl; 
        global++;
        return recursive_function(--x);
    }
}

class Shared {
private:
    std::recursive_mutex m;
public:
    Shared() {}
    Shared(const Shared &) = delete;
    Shared & operator=(const Shared &) = delete;
    
    void f() {
        std::unique_lock<std::recursive_mutex> l(m);
        std::cout << "Inside function f() " << std::endl;
    }    
    void g() {
        std::unique_lock<std::recursive_mutex> l(m);	
        std::cout << "Inside function g()" << std::endl;
        f();
    }
};

void body(int x)
{
    for (int i=0; i<1000000; i++); 
    std::cout << "1) I am the thread: " << x << std::endl;    
    recursive_function(x);
    for (int i=0; i<1000000; i++); 
}

void ObjThread(int index, Shared &x)
{
    cout << "Thread " << index << endl;
    x.g();
    cout << "Thread " << index << " terminated" << endl;
}


std::thread make_a_thread()
{
    return std::thread(body, 4);
}

int main()
{
    auto th = make_a_thread();
       
    std::cout << "Created" << std::endl;
    th.join();
    cout << "Global: " << global << endl;

    Shared obj;

    auto th1 = thread(ObjThread, 1, std::ref(obj));
    auto th2 = thread(ObjThread, 2, std::ref(obj));
    
    th1.join();
    th2.join();
}
