#ifndef _MAILBOX_H_
#define _MAILBOX_H_

#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

template<typename T>
class Mailbox {
    std::vector<T> v;
    unsigned head, tail;
    unsigned n;
    unsigned nmax;
    std::mutex m;
    std::condition_variable full;
    std::condition_variable empty;
public:
    Mailbox(unsigned places) : 
	v(places), head(0), tail(0), n(0), nmax(places) {}
    Mailbox(const Mailbox &mb) = delete;
    Mailbox& operator=(const Mailbox &) = delete;

    void put(T x);
    T get(); 
    bool is_empty();
};

template<typename T>
void Mailbox<T>::put(T x)
{
    std::unique_lock<std::mutex> lck(m); 
    while (n == nmax) full.wait(lck);     
    v[head] = x;
    n++;                                 
    head = (head + 1) % nmax;
    lck.unlock();
    empty.notify_one();
}                                        

template<typename T>
T Mailbox<T>::get()
{
    int ret = 0;
    std::unique_lock<std::mutex> lck(m); 
    while (n == 0) empty.wait(lck);
    ret = v[tail];
    tail = (tail + 1) % nmax;
    n--;
    lck.unlock();                      
    full.notify_one();               
                                          
    return ret;    
}    

template<typename T>
bool Mailbox<T>::is_empty()
{
    return (n == 0);
}

#endif /* _MAILBOX_H_ */

