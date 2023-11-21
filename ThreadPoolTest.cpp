#include <iostream>
#include <string>

#include "RandomSort.h"
using namespace std;
int main()
{
    string fileName = "../RandomFile/random1.txt";
    RandomSort rs(fileName.c_str());
    rs.MyFileSort();
    return 0;
}