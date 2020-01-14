#include <iostream>
#include <thread>
#include <chrono>

void body()
{
    std::cout << "This is a thread" << std::endl;    
    std::this_thread::sleep_for( std::chrono::seconds(1) );
    std::cout << "Am I still alive? " << std::endl;
}

void make_thread()
{
    std::thread mythread(body);
}

int main()
{
    using namespace std::chrono_literals;
    
    make_thread();
    //std::this_thread::sleep_for( std::chrono::seconds(3) );
    std::this_thread::sleep_for( 3s );
    return 0;
}
