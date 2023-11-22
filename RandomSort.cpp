#include "RandomSort.h"

RandomSort::RandomSort(string fileName)
{
    m_fileName = fileName;
    sortedNums.clear();

    fin.open(m_fileName);
    if(!fin.is_open()) {
        cout << "file not be opened!" << endl;
    }
}

RandomSort::~RandomSort()
{
    fin.close();
}

void RandomSort::MyFileSort()
{
    int64_t num;
    while(fin >> num) {
        sortedNums.push_back(num);
    }
    sort(sortedNums.begin(), sortedNums.end());
    return;
}

void RandomSort::PrintSortedNums()
{
    for(int i = 0; i < sortedNums.size(); i++) {
        cout << sortedNums[i]  << " " << endl;
    }
}

vector<int64_t> RandomSort::GetSortedNums()
{
    return sortedNums;
}