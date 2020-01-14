#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

std::mutex m;

void f(int x)
{
    for (int i=0; i<1000000; i++); 

    std::cout << "1) I am the thread: " << x << std::endl;    
}

int main()
{
    std::cout << "Before creating a thread" << std::endl;

    std::vector<std::thread> v;
    
    for (int i=0; i<10; i++) { v.push_back(std::thread(f, i)); }
    
    for (int i=0; i<1000000; i++); 

    std::cout << "2) After creating all threads" << std::endl;
    
    for (int i=0; i<10; i++) { v[i].join(); }
    
    std::cout << "Join" << std::endl;
}
