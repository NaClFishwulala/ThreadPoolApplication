#ifndef CLRANDOMSORT_H
#define CLRANDOMSORT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

class CLRandomSort
{
private:
    string m_fileName;
    vector<int64_t> sortedNums;
    ifstream fin;
public:
    CLRandomSort(string fileName);
    ~CLRandomSort();

    void MyFileSort();
    void PrintSortedNums();
    vector<int64_t> GetSortedNums();
};



#endif