#include <iostream>
#include <algorithm>

using namespace std;

template <typename Iterator, typename Fun> 
void apply(Iterator begin, Iterator end, Fun &f)
{
    for (auto i = begin; i!=end; ++i) f(*i);
} 


class SumFn {
    int sum;
public:
    SumFn() : sum(0) {}
    int get() { return sum; }
    void operator()(int x) {
        sum += x;
    }
};

class AvgFn {
    double sum;
    int n;
public:
    AvgFn() : sum(0.0), n(0) {}
    void operator()(int x) {
        sum += x;
        ++n;
    }
    double get() { return sum/n; }
};


int dumb_function(int x) 
{
    cout << "(" << x << ")" << endl;
    return 0;
}

int main() 
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = 0;
    for (auto x : v) 
        sum += x;
    cout << "The sum is: " << sum << endl;
    
    SumFn s;

    apply(v.begin(), v.end(), s);
    
    cout << "Sum (with functor) : " << s.get() << endl;
    
    AvgFn a;
    apply(v.begin(), v.end(), a);
    cout << "Avg (with functor) : " << a.get() << endl;

    apply(v.begin(), v.end(), dumb_function);
}
