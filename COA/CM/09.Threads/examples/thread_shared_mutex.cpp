#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

class ComplexDataStruct {
    shared_timed_mutex m;
public:
    ComplexDataStruct() {}
};

int main()
{
    ComplexDataStruct cd;
    return 0;
}
