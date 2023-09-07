#include <iostream>
using namespace std;

int nBitsInGivenPositiveNumber(int number)
{
    int count = 0;
    while (number > 0)
    {
        count += (number & 1);
        number = number >> 1;
    }
    return count;
}

int nBitsFast(int number)
{
    int count = 0;
    while (number > 0)
    {
        number = number & (number - 1);
        count++;
    }
    return count;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int number;
    cin >> number;
    cout << nBitsInGivenPositiveNumber(number) << endl;
    cout << nBitsFast(number) << endl;
}