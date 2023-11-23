#include <iostream>
#include <string>
#include <fstream>

#include "CLRandomSort.h"
#include "CLThreadPool.h"

using namespace std;
int main()
{
    // CLThreadPool mainThread;
    CLThreadPool& mainThread = CLThreadPool::GetInstance();
    mainThread.ThreadPoolStart();

    return 0;
}