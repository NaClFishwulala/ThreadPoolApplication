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
    fin >> num;
    cout << num << endl;
}