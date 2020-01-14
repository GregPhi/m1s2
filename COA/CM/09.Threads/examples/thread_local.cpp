#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <mutex>
#include <chrono>

using namespace std;

thread_local int index = 0;

mutex m;

void print(const std::string &s, int x) {
    unique_lock<mutex> l(m);
    cout << " x = " << x << ") " <<  s << " with index :" << index << endl;
    cout.flush();

}

void fun(int x) {
    print("fun() executing", x);
}

void body(int x)
{
    using namespace std::chrono_literals;

    index = x;
    print ("Thread started", x);

    this_thread::sleep_for( 1s );
    fun(x);    
    this_thread::sleep_for( 1s );

    print("Thread ended", x);
} 


int main()
{
    vector<int> indexes = {1, 2, 3, 4, 5};
    vector<thread> th;

    transform(indexes.begin(), indexes.end(),
	      back_inserter(th),
	      [](int x) { return thread(body, x); });

    for_each(th.begin(), th.end(),
	     [](thread &th) { th.join(); }); 
}
