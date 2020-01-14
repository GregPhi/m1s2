#include <thread>
#include <iostream>
#include <chrono>

using namespace std;

void f()
{
    cout << "This is a thread" << endl;
    try {
        this_thread::sleep_for( chrono::seconds(1) );
        throw "An exception has been thrown";
        cout << "This will not be printed" << endl;
    } catch (...) {
        cout << "Caught" << endl;
    }
}


int main()
{
    thread myth(f);
    
    cout << "Waiting for something to happen" << endl;

    myth.join();
    cout << "Ending" << endl;
}
