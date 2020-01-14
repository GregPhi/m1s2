#include <iostream>
#include "flist.hpp"

// create a list of consecutive integers
List<int> range(int a, int b, int delta)
{
    if (a >= b) return List<int>();
    else return List<int>(a, range(a+delta, b, delta));
}

// print the list 
template<typename T>
void print(List<T> lst)
{
    std::cout << "[";
    forEach(lst, [](T v) {
            std::cout << v << ", "; 
        });
    std::cout << "]" << std::endl;
}

// uses filter to remove all multiples of m from the list
List<int> removeMultFromList(int m, List<int> lst)
{
    return filter([m](int v) {
            return (v % m != 0);
        }, lst);
}

List<int> eratostene(List<int> lst)
{
    if (lst.isEmpty()) return List<int>();
    else return List<int>(lst.front(),
                          eratostene(removeMultFromList(lst.front(), lst.pop_front())));
}

int main(int argc, char * argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <limit>" << std::endl;
        exit(0);
    }
    
    int limit = atoi(argv[1]);
    
    List<int> init = List<int>(2, range(3, limit, 2));
    
    List<int> primesToN = eratostene(init);
    
    print(primesToN);
}
