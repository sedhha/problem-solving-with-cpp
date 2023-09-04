#include <iostream>
#include <algorithm>
using namespace std;

int findKthLargest(vector<int> nums, int k)
{
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int size, k;
    cin >> size >> k;
    vector<int> numbers(size);
    for(int i = 0; i < size; i++) {
        cin>>numbers[i];
    }
    cout<<findKthLargest(numbers, k);
    return 0;
}