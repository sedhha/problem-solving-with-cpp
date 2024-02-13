#include <iostream>

using namespace std;

int f(int n, vector<int> v, vector<int> &dp, int k)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int energy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int energyForNthJump = f(n - i, v, dp, k) + abs(v[n] - v[n - i]);
            energy = min(energy, energyForNthJump);
        }
    }
    return dp[n] = energy;
}

int fTab(int n, vector<int> v, int k)
{
    vector<int> dp(k, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int energy = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int energyForNthJump = dp[i - j] + abs(v[i] - v[i - j]);
                energy = min(energy, energyForNthJump);
            }
        }
        dp[i] = energy;
    }
    return dp[n - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    vector<int> dp(n + 1, -1);
    cout << "Result: " << f(n - 1, input, dp, k) << endl;
    cout << "Result fTab: " << fTab(n, input, k) << endl;
    return 0;
}