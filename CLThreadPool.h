#ifndef CLTHREADPOOL_H
#define CLTHREADPOOL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>

using namespace std;

class CLThreadPool
{
private:
    vector<thread> threadLists;
    vector<int64_t> retNums;
    vector<string> fileNames;
    static queue<vector<int64_t>> messageQue;
    static mutex messageQueMutex;
    int threadCount;
public:
    CLThreadPool();
    ~CLThreadPool();

    void ThreadPoolStart();
    static void ThreadRun(string fileName);

    void SetRetNums(vector<int64_t> nums);
    void SaveRetNums();
};



#endif