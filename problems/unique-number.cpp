#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

#endif

    int size, num, xorResult = 0;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        xorResult = num ^ xorResult;
    }
    cout << xorResult << endl;
}