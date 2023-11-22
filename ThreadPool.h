#ifndef THREADPOOL
#define THREADPOOL 
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ThreadPool
{
private:
    vector<int64_t> ret;
public:
    ThreadPool();
    ~ThreadPool();

    void SetRetNums(vector<int64_t> nums);
    void SaveRetNums();
};



#endif