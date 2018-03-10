#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <future>
#include <numeric>
#include <thread>
#include <random>

#include "e2.cc"

// DEBUG MODE
#define TEST 0
#define EN_MULTI_THREADS 1
#define THREAD_NUM 16
#define VEC_SIZE 50000000
#define TASK_PER_THREAD VEC_SIZE/THREAD_NUM
//create shortcut
namespace sc = std::chrono;

int main() {

    std::vector<int> myVec (VEC_SIZE);   //50000000
    std::srand(0);

    //another, better option would be to use std::generate and a c++11ish random generator
    for(int i = 0; i < myVec.capacity(); ++i) {
        myVec[i] = std::rand() % 1000;
    }

    //http://en.cppreference.com/w/cpp/chrono
    auto start = sc::high_resolution_clock::now();

    int minVal;
    int maxVal;
    long sum;
    double average;

    // New Defination Here...
    Solution<std::vector<int>::iterator, int> thr[THREAD_NUM]; //8 threads
    std::future<void> foo[THREAD_NUM];
    std::vector<int>::iterator it = myVec.begin();

    std::thread::id main_t = std::this_thread::get_id();


    //todo:  insert code here to populate these values
    //       the final execution time must be faster
    //       than what can be achieved with a single thread
    //      bonus points will be rewarded for fastest times
#if TEST //Test for basic functions
    Solution<std::vector<int>::iterator, int> sol;

    std::vector<int> my = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = my.begin();
    sol.iterate(my.begin(), 5);

    std::cout << sol.Show_Sum() <<std::endl;
    std::cout << sol.Show_Max() << std::endl;
    std::cout << sol.Show_Min() << std::endl;
    std::cout << "End Single Test" << std::endl;
#endif


#if EN_MULTI_THREADS  // Choose to use multi-thread

    for (int i = 0; (std::this_thread::get_id() == main_t) && (i < THREAD_NUM); ++i) {
        foo[i] = std::async(std::launch::async, [i, &thr, &myVec] {thr[i].iterate(i*TASK_PER_THREAD + myVec.begin(), TASK_PER_THREAD);});
    }
    for (int i = 0; i < THREAD_NUM ; ++i) {
        foo[i].get();
    }

    // Merge
    sum = 0;
    minVal = thr[0].Show_Min();
    maxVal = thr[0].Show_Max();
    for (int i = 0; i < THREAD_NUM ; ++i) {
        int min_tmp, max_tmp;
        min_tmp = thr[i].Show_Min();max_tmp = thr[i].Show_Max();

        sum += thr[i].Show_Sum();

        minVal = MIN(min_tmp, minVal);
        maxVal = MAX(max_tmp, maxVal);
    }
    average = (double) sum/VEC_SIZE;

#else // Single Thread
    Solution<std::vector<int>::iterator, int> single;

    single.iterate(myVec.begin(), myVec.size());

    minVal = single.Show_Min();
    maxVal = single.Show_Max();
    sum = single.Show_Sum();
    average = (double)sum/myVec.size();


#endif

    auto end = sc::high_resolution_clock::now();

    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    std::cout << "Elapsed Time: " << sc::duration_cast<sc::milliseconds>(end - start).count() << "ms" << std::endl;
}