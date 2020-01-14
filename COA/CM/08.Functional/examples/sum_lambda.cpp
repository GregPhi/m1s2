#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = 0;

    for_each(v.begin(), v.end(), 
	     [&sum](int x) { 
		 sum += x; 
	     });
    
    cout << "Sum (with lambda) : " << sum << endl;
    
    double d = 0; 
    int n = 0;
    for_each(v.begin(), v.end(), 
	     [&d, &n](int x) { 
		 d += x; ++n; 
	     });

    cout << "Avg (with lambda) : " << d/n << endl;
}
