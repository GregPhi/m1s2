#include <thread>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <numeric>

using namespace std;

const unsigned NELEM = 4000;

//array<array<int, NELEM>, NELEM> matrix;

int matrix[NELEM][NELEM]; 

void body(unsigned start, unsigned end, int &result)
{
    //int temp = 0;
 
    for (unsigned i=start; i<end; ++i) 
	for (unsigned j=0; j<NELEM; ++j) 
	    if (matrix[i][j] % 2) ++result; //++temp;
    
    //result = temp;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <nthreads> " << endl;
        exit(-1);
    }

    unsigned nthreads = atoi(argv[1]);
    
    cout << "Num threads: " << nthreads << endl;
    
    // fill the array
    for (unsigned i = 0; i < NELEM; ++i) {
        for (unsigned j = 0 ; j < NELEM; ++j) {
            matrix[i][j] = rand();
        }
    }
    
    vector<int> result(nthreads); 
    
    unsigned chunkSize = NELEM / nthreads + 1;
    cout << "chunkSize : " << chunkSize << endl;
    
    using std::chrono::duration_cast;
    using std::chrono::microseconds;
    using std::chrono::steady_clock;
 
    steady_clock::time_point start = steady_clock::now();
    
    vector<thread> th;
    for (unsigned p = 0; p<nthreads; ++p) {
        unsigned start = p * chunkSize;
        unsigned end = std::min( (p+1)*chunkSize, NELEM);
        cout << "[" << start << ", " << end << "]" << endl;
        th.emplace_back(thread(body, start, end, std::ref(result[p])));
    }
    
    for_each(th.begin(), th.end(), [](thread &t) {t.join();});
    
    int res = accumulate(result.begin(), result.end(), 0, std::plus<int>());

    steady_clock::time_point end = steady_clock::now();

    ofstream fout("scalability.txt", ios::app);

    cout << "Duration: " << duration_cast<microseconds>(end - start).count() << endl;
    cout << "Result " << res << endl;
    fout << nthreads << ", " << duration_cast<microseconds>(end - start).count() << endl;
    fout.close();
}
