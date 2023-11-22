#include "CLThreadPool.h"
#include "CLListDirCont.h"
#include "CLRandomSort.h"

queue<vector<int64_t>> CLThreadPool::messageQue;
mutex CLThreadPool::messageQueMutex;

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
        threadLists.push_back(thread(ThreadRun, fileNames[i]));
        threadCount++;
        threadLists[i].detach();
    }
    cout << "main thread" << endl;
    while(threadCount != 0) {
        messageQueMutex.lock();
        if(!messageQue.empty()) {
            messageQue.pop();
            threadCount--;
            cout << "messageQue pop, threadCount: " << threadCount << endl;
        }
        messageQueMutex.unlock();
    }
    
}

void CLThreadPool::SetRetNums(vector<int64_t> nums)
{
    retNums = nums;
}

void CLThreadPool::SaveRetNums()
{
    string outFileName = "../RandomFile/outfile.txt";
    ofstream fout;
    fout.open(outFileName.c_str());
    for(int i = 0; i < retNums.size(); i++) {
        fout << retNums[i] << " ";
    }
    fout.close();
}