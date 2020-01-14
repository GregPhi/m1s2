#include <iostream>
#include <thread>
#include <vector> 
#include <algorithm>

#include "barrier.hpp"
#include "var_printf.hpp"

using namespace std;

void body(int index, SyncBarrier &sb)
{
    using namespace std::chrono_literals;
    
    sb.sync();
    for (int i=0; i<10; i++) {
        unique_printf("Thread % step: %\n", index, i);	
        this_thread::sleep_for( 100ms );
        sb.sync();
    }
}

int main()
{
    SyncBarrier sb(5);
    vector<int> ind = {1, 2, 3, 4, 5};
    vector<thread> th;
    
    transform(ind.begin(), ind.end(),
	      back_inserter(th), 
              [&sb](int x) { 
                  return thread(body, x, std::ref(sb)); 
              });
    
    sb.start();
    
    for (int i=0; i<10; i++) sb.start();
    
    for_each(th.begin(), th.end(), 
             [](thread &th) {
                 th.join();
             });
    
    cout << "End" << endl;
}
