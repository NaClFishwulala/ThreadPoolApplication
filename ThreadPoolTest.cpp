#include <iostream>
#include <string>
#include <fstream>

#include "RandomSort.h"
#include "ThreadPool.h"

using namespace std;
int main()
{
    string fileName = "../RandomFile/random1.txt";
    RandomSort rs(fileName.c_str());
    rs.MyFileSort();
    vector<int64_t> ret = rs.GetSortedNums();

    ThreadPool mainThread;
    mainThread.SetRetNums(ret);
    mainThread.SaveRetNums();

    return 0;
}