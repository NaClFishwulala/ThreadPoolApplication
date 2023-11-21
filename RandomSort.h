#ifndef RANDOMSORT_H
#define RANDOMSORT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class RandomSort
{
private:
    string m_fileName;
    vector<int64_t> sortedNums;
    ifstream fin;
public:
    RandomSort(string fileName);
    ~RandomSort();

    void MyFileSort();
};



#endif