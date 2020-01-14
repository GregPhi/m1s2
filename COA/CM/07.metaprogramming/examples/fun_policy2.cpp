#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T> 
struct is_random_iterator {
    enum { value = false };
};

template<>
struct is_random_iterator<std::random_access_iterator_tag> {
    enum { value = true };
};

template<typename ItA, typename ItB, typename ItC>
void intersect(ItA a, ItA b, ItB c, ItB d, ItC res)
{
    typedef typename std::iterator_traits<ItA>::iterator_category tagA; 
    typedef typename std::iterator_traits<ItB>::iterator_category tagB; 

    static_assert(is_random_iterator<tagA>::value, 
		  "Cannot call interset on a non-random access iterator type");
    static_assert(is_random_iterator<tagB>::value, 
		  "Cannot call interset on a non-random access iterator type");
	
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

// void try_list()
// {
//     list<int> l1 = {1, 3, 3, 4, 6, 7, 9, 10, 12, 12};
//     list<int> l2 = {3, 4, 4, 6, 6, 9, 11, 12, 12, 13};
//     vector<int> v3;

//     //random_shuffle(begin(v1), end(v1));
//     //random_shuffle(begin(v2), end(v2));

//     print(begin(l1), end(l1));
//     print(begin(l2), end(l2));
//     print(begin(v3), end(v3));

//     intersect(begin(l1),end(l1), begin(l2), end(l2), back_inserter(v3));
	      
//     cout << " ---------------------- " << endl;
//     print(begin(l1), end(l1));
//     print(begin(l2), end(l2));
//     print(begin(v3), end(v3));
// }


int main()
{
    try_vector();
    //try_list();
    return 0;
}
