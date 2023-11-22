#include <fstream>
#include <iostream>
#include <random>
#include <climits>
using namespace std;

int main()
{
    random_device rd;  // 用于获取随机数种子
    mt19937_64 gen(rd()); // 使用64位 Mersenne Twister 19937 生成器
    uniform_int_distribution<int64_t> dis(LONG_MIN, LONG_MAX); // 生成均匀分布的随机数
    // cout << "min:" << dis.a() << " max:" << dis.b() << endl;
    ofstream fout;
    string fileName = "./random" + to_string(1) + ".txt";
    fout.open(fileName);
    for(int i = 0; i < 1024*1024; i++) {
        int64_t random_number = dis(gen);
        fout << dis(gen) << " ";
    }
    fout.close();
    return 0;
}