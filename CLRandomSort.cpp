#include "CLRandomSort.h"

CLRandomSort::CLRandomSort(string fileName)
{
    m_fileName = fileName;
    sortedNums.clear();

    fin.open(m_fileName);
    if(!fin.is_open()) {
        cout << "file not be opened!" << endl;
    }
}

CLRandomSort::~CLRandomSort()
{
    fin.close();
}

void CLRandomSort::MyFileSort()
{
    int64_t num;
    while(fin >> num) {
        sortedNums.push_back(num);
    }
    sort(sortedNums.begin(), sortedNums.end());
    return;
}

void CLRandomSort::PrintSortedNums()
{
    for(int i = 0; i < sortedNums.size(); i++) {
        cout << sortedNums[i]  << " " << endl;
    }
}

vector<int64_t> CLRandomSort::GetSortedNums()
{
    return sortedNums;
}