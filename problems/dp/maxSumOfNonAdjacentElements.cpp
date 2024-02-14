#include <iostream>

using namespace std;

/*
    Example:
    1 2 3 4 5 6 7 8 (n)
    int maxSum = INT_MIN;
    f8 =>
        8 + f6
        8 + f5
        8 + f4
        8 + f3
        8 + f2
        8 + f1
        maxSum = max(maxSum, curr);
    int maxSum = INT_MIN;
    if(dp[n] != -1) return maxSum;
    for(int i = n; i >= 0; i--) { 2,1,0
        int currSum = v[i]; // 2
        if(i - 2 >= 0)
            currSum += f(i - 2); // 4
        maxSum = max(maxSum, currSum); 4
    }
    return maxSum = dp[n]; // f(0) = 1;
    // f(1) = 2;
    // f(2) = 4;

*/

int f(int n, vector<int> v, vector<int> &dp)
{
    if (dp[n] != -1)
        return dp[n];
    int maxSum = INT_MIN;

    for (int i = n; i >= 0; i--)
    {
        int currSum = v[i];
        if (i - 2 >= 0)
            currSum += f(i - 2, v, dp);
        maxSum = max(maxSum, currSum);
    }
    return dp[n] = maxSum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> dp(n, -1);
    cout << "Max Sum: " << f(n - 1, nums, dp) << endl;

    return 0;
}