#include <iostream>
#include "CLListDirCont.h"

using namespace std;

CLListDirCont::CLListDirCont()
{
    dir = opendir("../RandomFile/");
    totalFile = 0;
    fileNames.clear();
    if(dir == NULL) {
        cout << "error opendir" << endl;
    }
    cout << "success opendir" << endl;
}

CLListDirCont::~CLListDirCont()
{
    if(closedir(dir) == -1) {
        cout << "error closedir" << endl;
    }
    cout << "success closedir" << endl;
}

CLListDirCont& CLListDirCont::GetInstance()
{
    static CLListDirCont m_dp;
    return m_dp; 
}

void CLListDirCont::ListDirCont()
{
    struct dirent *ptr;
    while((ptr=readdir(dir))!=NULL)
    {
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {
            continue;
        }
        string fileName =  ptr->d_name;
        fileNames.push_back("../RandomFile/" + fileName);
        totalFile++;
    }
    cout << "totalFile: " << totalFile << endl;
}

vector<string> CLListDirCont::GetFileNames()
{
    return fileNames;
}