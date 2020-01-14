#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>
#include "barrier.hpp"

using namespace std;

const double COEFF = 2;

void body(SyncBarrier &sb, 
          std::vector<double> &v, 
          std::vector<double> &res,
          unsigned start, unsigned end)
{
    while (sb.sync()) {
        for (unsigned i=start; i < end; ++i) {
            if (i == 0) 
                res[i] = (COEFF*v[i] + v[i+1])/(COEFF + 1); 
            else if (i == (v.size()-1)) 
                res[i] = (v[i-1] + COEFF*v[i])/(COEFF + 1);
            else 
                res[i] = (v[i-1] + COEFF*v[i] + v[i+1])/(COEFF + 2);
        }
    }
}

unsigned VSIZE = 20;
unsigned NTHREADS = std::thread::hardware_concurrency();

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <sim_len> [num_th] [vsize]" << endl; 
        exit(-1);
    }
    
    unsigned simlen = atoi(argv[1]);
    
    if (argc >= 3) 
        NTHREADS = atoi(argv[2]);
    
    if (argc == 4) 
        VSIZE = atoi(argv[3]);
	
    vector<double> vec(VSIZE); vec[0] = 100;
    vector<double> res(VSIZE); 
    vector<thread> th;
    
    cout << "Number of threads: " << NTHREADS << endl;
    cout << "Hardware concurrency: " << std::thread::hardware_concurrency() << endl;
    cout << "Sim len          : " << simlen << endl;
    cout << "Vector size      : " << VSIZE << endl;
    
    SyncBarrier sb(NTHREADS);
    
    unsigned start = 0;
    for (unsigned i=0; i<NTHREADS; ++i) {
        unsigned end = start + VSIZE/NTHREADS;
        if (i == NTHREADS-1) end = VSIZE;
        th.emplace_back(thread(body, std::ref(sb), std::ref(vec), std::ref(res), start, end));
        start = end;
    }
    
    for (unsigned i=0; i<simlen; i++) {
        sb.start();
        sb.wait();
        vec.swap(res);
    }
    sb.start(false);
    for_each(th.begin(), th.end(), [](thread &t) { t.join(); });

    // final print
    for_each(vec.begin(), vec.end(), [](double x) { cout << x << ", "; });
    cout << endl;
}
