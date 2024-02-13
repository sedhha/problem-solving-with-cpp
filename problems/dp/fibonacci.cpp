#include <iostream>
using namespace std;
// Computes Fibonacci Recursively
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciWithDp(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibonacciWithDp(n - 1, dp) + fibonacciWithDp(n - 2, dp);
    return dp[n];
}

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int fibonacciWithDpNonRecursive(int n)
{
    vector<int> dp(n + 1, -1);
    if (n <= 1)
        return n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int fibonacciLinear(int n)
{
    int prev = 1;
    int prev2 = 0;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << "Fibonacci using Recursion: " << fibonacci(n) << endl;

    vector<int> dp(n + 1, -1);
    cout
        << "Fibonacci using DP Recursion: " << fibonacciWithDp(n, dp) << endl;
    cout
        << "Fibonacci using DP Non Recursion: " << fibonacciWithDpNonRecursive(n) << endl;

    cout << "Fibonacci using linear space: " << fibonacciLinear(n) << endl;
    return 0;
}