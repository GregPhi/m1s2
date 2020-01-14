#include <iostream>

template<bool f, typename T, typename U>
struct Select {};

template<typename T, typename U>
struct Select<true, T, U> { typedef T Type; };
    
template<typename T, typename U>
struct Select<false, T, U> { typedef U Type; };

using namespace std;

int main()
{
    const int x = 5;
    
    Select< (x<10), int, double >::Type y = 5.5;
    Select< (x>=10), int, double >::Type z = 5.5;
    
    cout << y << endl;
    cout << z << endl;
}
