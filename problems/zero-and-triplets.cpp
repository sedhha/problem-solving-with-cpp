/*
    Given an integer array nums, return the number of AND triples where ANDing is 0.

An AND triple is a triple of indices (i, j, k) such that:

0 <= i < nums.length

0 <= j < nums.length

0 <= k < nums.length

nums[i] & nums[j] & nums[k] == 0, where & represents the bitwise-AND operator.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int countTriplets(vector<int> nums)
{
    int size = nums.size();
    int totalCount = 0;
    unordered_map<int, int> andPair;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            andPair[nums[i] & nums[j]]++;
    for (auto i = andPair.begin(); i != andPair.end(); i++)
    {
        int result = i->first;
        int count = i->second;
        for (int num : nums)
        {
            if ((result & num) == 0)
                totalCount += count;
        }
    }

    return totalCount;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Triplet Count = " << countTriplets(nums) << endl;
}