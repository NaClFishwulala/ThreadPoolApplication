#include "CLThreadPool.h"
#include "CLListDirCont.h"
#include "CLRandomSort.h"

// queue<vector<int64_t>> CLThreadPool::messageQue;
// mutex CLThreadPool::messageQueMutex;

CLThreadPool::CLThreadPool()
{
    // 此处获取所有待排序文件
    CLListDirCont &dp = CLListDirCont::GetInstance();
    dp.ListDirCont();
    fileNames.clear();
    fileNames = dp.GetFileNames();

    retNums.clear();
    threadCount = 0;
}

CLThreadPool::~CLThreadPool()
{
    for(int i = 0; i < fileNames.size(); i++) {
        threadLists[i].join();
    }
    SaveRetNums();
}


void CLThreadPool::ThreadRun(string fileName)
{
    CLRandomSort rs(fileName.c_str());
    rs.MyFileSort();
    vector<int64_t> ret = rs.GetSortedNums();
    messageQueMutex.lock();
    messageQue.push(ret);
    cout << fileName << " push" << endl;
    messageQueMutex.unlock();
    return;
}

void CLThreadPool::ThreadPoolStart()
{
    for(int i = 0; i < fileNames.size(); i++) {
        threadLists.push_back(thread(&CLThreadPool::ThreadRun, this, fileNames[i]));
        threadCount++;
    }
    cout << "main thread" << endl;
    while(threadCount != 0) {
        if(!messageQue.empty()) {
            vector<int64_t> messageNums;
            messageQueMutex.lock();
            messageNums = messageQue.front();
            messageQue.pop();
            threadCount--;
            cout << "messageQue pop, threadCount: " << threadCount << endl;
            messageQueMutex.unlock();
            MergeSort(messageNums);
        }

    }
}

void CLThreadPool::SetRetNums(vector<int64_t> nums)
{
    retNums = nums;
}

void CLThreadPool::SaveRetNums()
{
    string outFileName = "../outfile.txt";
    ofstream fout;
    fout.open(outFileName.c_str());
    for(int i = 0; i < retNums.size(); i++) {
        fout << retNums[i] << " ";
    }
    fout.close();
}

CLThreadPool& CLThreadPool::GetInstance()
{
    static CLThreadPool m_threadPool;
    return m_threadPool;
}

void  CLThreadPool::MergeSort(vector<int64_t> &nums)
{
    int i = 0;
    int j = 0;
    vector<int64_t> newNums;
    while(i < retNums.size() && j < nums.size()) {
        if(retNums[i] <= nums[j]) {
            newNums.push_back(retNums[i]);
            i++;
        } else {
            newNums.push_back(nums[j]);
            j++;
        }
    }
    while(i < retNums.size()) {
        newNums.push_back(retNums[i]);
        i++;
    }
    while(j < nums.size()) {
        newNums.push_back(nums[j]);
        j++;
    }
    retNums = newNums;
    return;
}