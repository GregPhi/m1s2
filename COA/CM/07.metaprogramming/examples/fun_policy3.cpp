#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

template<typename T> 
struct is_random_iterator {
    enum { value = false };
};

template<>
struct is_random_iterator<std::random_access_iterator_tag> {
    enum { value = true };
};

// the generic version
template<typename ItA, typename ItB, typename ItC, typename TypeA, typename TypeB>
void intersect_opt(ItA a, ItA b, ItB c, ItB d, ItC res, TypeA, TypeB)
{
    typedef typename std::iterator_traits<ItA>::value_type ValueT;
 
    std::set<ValueT> temp;
    for (auto x=a;x!=b;++x) 
        for (auto y=c; y!=d; ++y) {
            if (*x == *y and temp.find(*x) == temp.end()) 
                temp.insert(*x);
        }
    for (auto e : temp) *res++ = e;
}

// the optimized version for two vectors
template<typename ItA, typename ItB, typename ItC>
void intersect_opt(ItA a, ItA b, ItB c, ItB d, ItC res, 
                   std::random_access_iterator_tag, std::random_access_iterator_tag)
{
    sort(a, b);
    sort(c, d);

    auto x = a; auto y = c;
    while (x != b && y != d) 
        if (*x == *y) { 
            *res++ = *x;
            while (*x == *y) ++x; 
            ++y;
        } 
        else if (*x < *y) ++x;
        else if (*y < *x) ++y;
}


template<typename ItA, typename ItB, typename ItC> 
void intersect(ItA a, ItA b, ItB c, ItB d, ItC res)
{
    typedef typename std::iterator_traits<ItA>::iterator_category tagA; 
    typedef typename std::iterator_traits<ItB>::iterator_category tagB; 
    intersect_opt(a, b, c, d, res, tagA(), tagB());
}


template<typename It> 
void print(It a, It b)
{
    std::cout << "[";
    for (auto i=a; i!=b ; ++i) cout << *i << ", ";
    std::cout << "]" << std::endl;
}

void try_vector()
{
    vector<int> v1 = {1, 3, 3, 4, 6, 7, 9, 10, 12, 12};
    vector<int> v2 = {3, 4, 4, 6, 6, 9, 11, 12, 12, 13};
    vector<int> v3;

    random_shuffle(begin(v1), end(v1));
    random_shuffle(begin(v2), end(v2));

    print(begin(v1), end(v1));
    print(begin(v2), end(v2));
    print(begin(v3), end(v3));

    intersect(begin(v1),end(v1), begin(v2), end(v2), back_inserter(v3));
	      
    cout << " ---------------------- " << endl;
    print(begin(v1), end(v1));
    print(begin(v2), end(v2));
    print(begin(v3), end(v3));
}

void try_list()
{
    list<int> l1 = {1, 3, 3, 4, 6, 7, 9, 10, 12, 12};
    list<int> l2 = {3, 4, 4, 6, 6, 9, 11, 12, 12, 13};
    vector<int> v3;

    //random_shuffle(begin(v1), end(v1));
    //random_shuffle(begin(v2), end(v2));

    print(begin(l1), end(l1));
    print(begin(l2), end(l2));
    print(begin(v3), end(v3));

    intersect(begin(l1),end(l1), begin(l2), end(l2), back_inserter(v3));
	      
    cout << " ---------------------- " << endl;
    print(begin(l1), end(l1));
    print(begin(l2), end(l2));
    print(begin(v3), end(v3));
}


int main()
{
    cout << "Vector:" << endl;
    try_vector();
    cout << "LIST:" << endl;
    try_list();
    return 0;
}
