#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

void thr(int x)
{
    for (int i=0; i<1000000; i++); 
    
    std::cout << x << ") Thread started" << std::endl;    

    for (int i=0; i<1000000; i++);     
}

std::thread make_a_thread(int x)
{
    return std::thread(thr, x);
}

int main()
{
    std::vector<int> vind = {1, 2, 3, 4, 5};
    std::vector<std::thread> vt;
    
    std::transform(vind.begin(), vind.end(), std::back_inserter(vt), make_a_thread);
    std::for_each(vt.begin(), vt.end(), std::mem_fn(&std::thread::join));

    std::cout << "Finished" << std::endl;
}
