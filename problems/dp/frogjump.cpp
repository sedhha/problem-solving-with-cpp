// Given a frog can jump 1 or 2 steps in a staircase compute the minimum energy required.
// Energies are given as array of numbers (int)

#include <iostream>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int traversePaths(int n, vector<int> v)
{
    if (n <= 0)
        return 0;

    int oneStepJump = traversePaths(n - 1, v) + abs(v[n] - v[n - 1]);
    int twoStepJump = INT_MAX;
    if (n - 2 >= 0)
        twoStepJump = traversePaths(n - 2, v) + abs(v[n] - v[n - 2]);
    return min(oneStepJump, twoStepJump);
}

int traversePathsDp(int n, vector<int> v, vector<int> &paths)
{
    if (n <= 0)
        return 0;
    if (paths[n] != -1)
        return paths[n];

    int oneStepJump;
    int twoStepJump = INT_MAX;
    printVector(v);
    printVector(paths);

    oneStepJump = traversePathsDp(n - 1, v, paths) + abs(v[n] - v[n - 1]);
    if (n - 2 >= 0)
    {
        twoStepJump = traversePathsDp(n - 2, v, paths) + abs(v[n] - v[n - 2]);
    }

    return paths[n] = min(oneStepJump, twoStepJump);
}

int f(int n, vector<int> v, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = f(n - 1, v, dp) + abs(v[n] - v[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = f(n - 2, v, dp) + abs(v[n] - v[n - 2]);
    return dp[n] = min(left, right);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif
    int n; // Number of steps
    cin >> n;
    vector<int> steps(n);
    for (int i = 0; i < n; i++)
        cin >> steps[i];
    vector<int> dp(n + 1, -1);
    cout
        << "PATH on Frog Jump: " << f(n - 1, steps, dp) << endl;

    return 0;
}