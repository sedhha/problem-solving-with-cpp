#include <iostream>
#include <cmath>
using namespace std;

int getLastBit(int n)
{
    return n & 00000001;
}

int getBinaryOfNumber(int num)
{
    int power = 0;
    int result = 0;
    while (num > 0)
    {
        int lastBit = getLastBit(num);
        result += pow(10, power++) * lastBit;
        num = num >> 1;
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int num;
    cin >> num;
    cout << getBinaryOfNumber(num) << endl;
}