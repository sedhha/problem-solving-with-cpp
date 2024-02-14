#include <iostream>
using namespace std;
/*
Mr. X is a professional robber planning to rob houses along a street.
Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle.
That means the first house is the neighbour of the last one.
Meanwhile, adjacent houses have a security system connected, and it will
automatically contact the police if two adjacent houses are broken into on the
same night.

You are given an array/list of non-negative integers 'ARR' representing the amount
of money of each house. Your task is to return the maximum amount of money Mr. X
can rob tonight without alerting the police.
*/

int f(int n, vector<int> v, vector<int> &dp)
{
    if (n == 0)
        return v[0];

    int pick = v[n];
    if (n - 2 >= 0)
        pick += f(n - 2, v, dp);
    int notPick = INT_MIN;
    if (n - 1 >= 0)
        notPick = f(n - 1, v, dp);
    int maxValue = max(pick, notPick);
    return dp[n] = maxValue;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif
    int inputs;
    cin >> inputs;
    for (int i = 0; i < inputs; i++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++)
            cin >> v[j];
        vector<int> temp1, temp2;
        for (int k = 0; k < n; k++)
        {
            if (k != 0)
                temp1.push_back(v[k]);
            if (k != n - 1)
                temp2.push_back(v[k]);
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int result1 = f(n - 2, temp1, dp1);
        int result2 = f(n - 2, temp2, dp2);
        cout << "Result: " << max(result1, result2) << endl;
    }
}