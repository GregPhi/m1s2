#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void body()
{
    cout << "This is a thread" << endl;    
    this_thread::sleep_for( chrono::seconds(1) );
    cout << "Am I still alive? " << endl;
}
void make_thread()
{
    thread mythread(body);
    mythread.detach();
}
int main()
{
    make_thread();
    this_thread::sleep_for( chrono::seconds(3) );   
    return 0;
}




