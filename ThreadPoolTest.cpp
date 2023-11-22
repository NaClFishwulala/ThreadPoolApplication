#include <iostream>
#include <string>
#include <fstream>

#include "CLRandomSort.h"
#include "CLThreadPool.h"

using namespace std;
int main()
{
    // string fileName = "../RandomFile/random1.txt";
    // CLRandomSort rs(fileName.c_str());
    // rs.MyFileSort();
    // vector<int64_t> ret = rs.GetSortedNums();

    CLThreadPool mainThread;
    mainThread.ThreadPoolStart();

    return 0;
}