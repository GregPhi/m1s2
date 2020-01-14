#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
    

template <typename It>
void print(It b, It e) {
    cout << "{";
    if (b == e) {
        cout << "}" << endl;
        return;
    }
    else {
        cout << *b;
        for (It i = b+1; i!= e; i++) {
            cout << ", " << *i;
        }
        cout << "}" << endl;
    }
}


int main()
{
     vector<int> vec = {4, 1, 9, 5, 10, 15, 3, 7};

     sort(begin(vec), end(vec));

     // sums all elements
     cout << "Sum: " <<  accumulate(begin(vec), end(vec), 0) << endl;

     // multiplies all elements
     cout << "Multiply: " << accumulate(begin(vec), end(vec), 1,
                                        multiplies<int>()) << endl;

     // sums all elements, except the first and the last
     cout << "Partial sum : " << accumulate(next(begin(vec)), prev(end(vec)), 0) << endl;
  
     vector<int> ve2 = {2, 3, 5, 2, 5, 7, 9, 10, 9, 7, 1, 2};
     print(begin(ve2), end(ve2));
     sort(begin(ve2), end(ve2));
     auto it = unique(begin(ve2), end(ve2));
     ve2.erase(it, end(ve2));
     print(begin(ve2), end(ve2));
}
