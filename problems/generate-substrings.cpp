#include <iostream>
#include <cstring>
using namespace std;

void overlayNumber(char arr[], int num)
{
    int j = 0;
    while (num > 0)
    {
        int ithBit = num & 1;
        if (ithBit)
            cout << arr[j];
        j++;
        num = num >> 1;
    }
    cout << endl;
}

void generateSubsets(char arr[])
{
    int n = strlen(arr);
    for (int i = 0; i < (1 << n) - 1; i++)
        overlayNumber(arr, i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    char arr[10000];
    cin >> arr;
    generateSubsets(arr);
}