#include <vector>
#include <iostream>

template<typename Iter, typename Fun>
void apply(Iter b, Iter e, Fun f)
{  
   	for (Iter i = b; i != e; i++) f(*i); 
}


int main() 
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    int sum = 0;
    
    apply(std::begin(v), std::end(v), [&sum](int x) { sum += x; });
    
    std::cout << "sum = " << sum << std::endl;
}
