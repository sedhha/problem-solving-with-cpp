#include <iostream>
#include <algorithm>
using namespace std;

void printVector(vector<int> v)
{
    for (int i : v)
        cout << i << ",";
    cout << endl;
}

int solve(vector<int> nums)
{
    int sum = 0;
    sort(nums.begin(), nums.end()); // O(N)
    while (nums.size() != 1)
    {
        int newValue = nums[0] + nums[1];
        sum += newValue;
        nums = vector<int>(nums.begin() + 2, nums.end()); // O(N)
        nums.push_back(newValue);
        sort(nums.begin(), nums.end()); // O(N)
    }
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int size;
    cin >> size;
    vector<int> numbers(size);
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }
    cout << solve(numbers);
    return 0;
}