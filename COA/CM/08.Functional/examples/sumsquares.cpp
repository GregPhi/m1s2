#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> v = {3.0, -4.0, 2.0, -1.1, 0.5 };
    std::vector<double> r;

    std::transform(begin(v), end(v), 
                   std::back_inserter(r), 
                   [] (double x) { return x*x; });
    
    auto result = std::accumulate(begin(r), end(r), 0.0);
    
    for (auto x : r) std::cout << x << ", ";
    std::cout << "\n";
    std::cout << "Sum of squares: " << result << "\n";
}
