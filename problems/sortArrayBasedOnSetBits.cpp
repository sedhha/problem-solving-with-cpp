#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ",";
    }
    cout << endl;
}

int countSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        num = num & (num - 1);
        count++;
    }
    return count;
}

bool moreSetBits(const int a, const int b)
{
    return countSetBits(a) < countSetBits(b);
}

vector<int> sortByBits(vector<int> arr)
{
    sort(arr.begin(), arr.end(), moreSetBits);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

#endif
    int n;
    cin >> n;
    vector<int> arr;
    int inputNum;
    for (int i = 0; i < n; i++)
    {
        cin >> inputNum;
        arr.push_back(inputNum);
    }
    sortByBits(arr);
    printVector(arr);
}