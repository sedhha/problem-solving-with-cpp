#include <iostream>
#include <vector>
using namespace std;

void computeTwoDistinctNumbers(vector<int> nums)
{
    int xorNumber = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xorNumber = xorNumber ^ nums[i];
    }
    int firstSetBitPos = 0;
    int temp = xorNumber;
    while ((temp & 1) == 0)
    {
        firstSetBitPos++;
        temp = temp >> 1;
    }
    int setA = 0;
    int setB = 0;
    int mask = 1 << firstSetBitPos;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((mask & nums[i]) > 0)
            setA ^= nums[i];
        else
            setB ^= nums[i];
    }
    cout << "Numbers are " << setA << " and " << setB << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

#endif

    int size, num;
    cin >> size;
    vector<int> nums(size, 0);

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        nums[i] = num;
    }
    computeTwoDistinctNumbers(nums);
}