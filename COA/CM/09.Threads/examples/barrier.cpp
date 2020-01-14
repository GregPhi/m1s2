#include "barrier.hpp"

bool SyncBarrier::sync()
{
    std::unique_lock<std::mutex> lck(m);
    nblocked++;

    if (nblocked == max_threads) 
	mng.notify_one();
    c.wait(lck);
    return flag;
}

void SyncBarrier::start(bool fl)
{
    std::unique_lock<std::mutex> lck(m);
    while (nblocked < max_threads) mng.wait(lck);
    nblocked = 0;
    flag = fl;
    c.notify_all();
}

void SyncBarrier::wait()
{
    std::unique_lock<std::mutex> lck(m);
    while (nblocked < max_threads) mng.wait(lck);
}
