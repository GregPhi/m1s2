#ifndef _BARRIER_H_
#define _BARRIER_H_

#include <mutex> 
#include <condition_variable>

class SyncBarrier {
    std::mutex m;
    std::condition_variable c;
    std::condition_variable mng;
    const int max_threads;
    int nblocked;
    bool flag;
public:
    SyncBarrier(int mt) : max_threads(mt), nblocked(0), flag(true) { }

    bool sync();
    void start(bool cont = true);
    void wait();
};

#endif /* _BARRIER_H_ */
