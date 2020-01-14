#include <thread>
#include <iostream>
#include <chrono>
#include <atomic>

using namespace std;

class ActiveObject {
    int mydata = 0;
    std::thread myth;
    std::atomic<bool> stopped;
public:
    ActiveObject(int d) : mydata(d), myth(&ActiveObject::run, this) {
	stopped = false;
    }
    
    void run() {
	cout << "This is thread n. " << mydata << endl;
	while (! stopped) {
	    cout << mydata << ") here I am" << endl;
	    std::this_thread::sleep_for( std::chrono::seconds(1) );
	}
    }

    void stop() {
	stopped = true;
	myth.join();
    }
};


int main()
{
    ActiveObject a(1);
    ActiveObject b(2);
    
    std::this_thread::sleep_for( std::chrono::seconds(5) );
    
    a.stop();
    b.stop();
}
