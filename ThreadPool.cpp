#include "ThreadPool.h"

ThreadPool::ThreadPool(/* args */)
{
    ret.clear();
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::SetRetNums(vector<int64_t> nums)
{
    ret = nums;
}

void ThreadPool::SaveRetNums()
{
    string outFileName = "../RandomFile/outfile.txt";
    ofstream fout;
    fout.open(outFileName.c_str());
    for(int i = 0; i < ret.size(); i++) {
        fout << ret[i] << " ";
    }
    fout.close();
}