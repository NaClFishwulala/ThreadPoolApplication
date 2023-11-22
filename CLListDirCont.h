#ifndef CLLISTDIRCONT_H
#define CLLISTDIRCONT_H
#include <dirent.h>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CLListDirCont
{
private:
    DIR* dir;
    vector<string> fileNames;
    unsigned int totalFile;

private:
    CLListDirCont();
    ~CLListDirCont();
public:
    static CLListDirCont& GetInstance();
    void ListDirCont();
    vector<string> GetFileNames();
};

#endif