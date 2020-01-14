#include <iostream>
#include <cstdlib>
#include "flist.hpp"
#include "var_printf.hpp"

// Creates a list of consecutive integers
List<int> range(int a, int b, int delta)
{
    if (a>=b) return List<int>();
    else return List<int>(a, range(a+delta, b, delta));
}

// prints a list
template<class T>
void print(List<T> l) 
{
    if (l.isEmpty()) return;
    else  {
        std::cout << l.front() << ", ";
        print(l.pop_front());
    }
}

// given two lists, returns the set difference 
List<int> subtract(List<int> l1, List<int> l2)
{
    if (l1.isEmpty()) return l1;
    else if (l2.isEmpty()) return l1;
    else if (l1.front() < l2.front()) 
        return List<int>(l1.front(), subtract(l1.pop_front(), l2));
    else if (l1.front() == l2.front()) 
        return subtract(l1.pop_front(), l2.pop_front());
    else // (l1.front() > l2.front()) 
        return subtract(l1, l2.pop_front());
}


// The basic eratostene algorithm: 
// remove all multiples of the first element from the list
List<int> eratostene(List<int> l, int limit)
{
    if (l.isEmpty()) return l;
    else return List<int>(l.front(),
                          eratostene(
                              subtract(l.pop_front(),
                                       range(l.front() * l.front(),
                                             limit, 
                                             l.front())), limit));
}

List<int> primes(int limit)
{
    return List<int>(2, eratostene(range(3, limit, 2), limit));
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        safe_printf("Usage % <num>\n", argv[0]);
        exit(0);
    }
    
    int limit = atoi(argv[1]);
    safe_printf("All primes up to %\n", limit);
    
    std::cout << "[";
    print(primes(limit));
    std::cout << "]" << std::endl;
}
