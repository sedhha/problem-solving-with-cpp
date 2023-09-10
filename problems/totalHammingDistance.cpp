#include <iostream>
#include <vector>
using namespace std;

int hammingDistanceBetweenTwoNums(int num1, int num2)
{
    int count = 0;
    int biggerNum = num1 > num2 ? num1 : num2;
    int smallerNum = num1 <= num2 ? num1 : num2;

    while (biggerNum > 0)
    {
        int lastBitOfBiggerNum = biggerNum & 1;
        int lastBitOfSmallerNum = smallerNum & 1;
        count += lastBitOfBiggerNum != lastBitOfSmallerNum;
        biggerNum >>= 1;
        smallerNum >>= 1;
    }
    return count;
}

int totalHammingDistance(vector<int> nums)
{
    int totalHammingDistance = 0;
    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++)
            totalHammingDistance += hammingDistanceBetweenTwoNums(nums[i], nums[j]);

    return totalHammingDistance;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int size;
    cin >> size;
    vector<int> nums(size, 0);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    cout << "Result = " << totalHammingDistance(nums);
    return 0;
}