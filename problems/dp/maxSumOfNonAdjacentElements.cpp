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

    INPUT:
    3
    6
    10 4 6 4 5 8
    4
    1 2 3 4
    2
    1 2

    OUTPUT:
    Max Sum: 24
    Max Sum when tabulation: 24
    Max Sum: 6
    Max Sum when tabulation: 6
    Max Sum: 2
    Max Sum when tabulation: 2
    ---------------------------------------------------------
    APPROACH 2: (PICK OR NOT PICK)
    1 2 4
    f(N) =>
            if(N == 0) return V[N];
            case pick:
                int currSum = v[N]; // 4
                if(N-2 >= 0)
                    currSum += f(N - 2); // 6
                // 2
            case notPick:
                int currSum = INT_MIN;
                if(N-1 >= 0)
                    currSum =  f(N - 1); // f(1) = 2
            maxSum = max(pick, notPick); // 6
            return dp[N] = maxSum; [-1, 2, 6]


*/

int fPickNotPick(int n, vector<int> v, vector<int> &dp)
{
    if (n == 0)
        return v[0];

    int pick = v[n];
    if (n - 2 >= 0)
        pick += fPickNotPick(n - 2, v, dp);
    int notPick = INT_MIN;
    if (n - 1 >= 0)
        notPick = fPickNotPick(n - 1, v, dp);
    int maxValue = max(pick, notPick);
    return dp[n] = maxValue;
}

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

int fTabulation(int n, vector<int> v)
{
    vector<int> dp(n, -1);
    if (n == 0)
        return 0;
    dp[0] = v[0];
    for (int i = 0; i <= n; i++)
    {
        int maxSum = INT_MIN;
        for (int j = 0; j <= i; j++) // 0 1 2 3 (3)
        {
            int currSum = v[i]; // 4
            if (j - 2 >= 0)
                currSum += dp[j - 2]; // 14
            maxSum = max(currSum, maxSum);
        }
        dp[i] = maxSum; // dp[0] = 0,
        // dp[1] = 4, dp[2] = 16
        //
    }
    return dp[n];
}
void printVector(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif

    int numOfInputs;
    cin >> numOfInputs;
    for (int i = 0; i < numOfInputs; i++)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        vector<int> dp(n, -1);
        cout << "Using Recursion: " << f(n - 1, nums, dp) << endl;
        cout << "Using tabulation: " << fTabulation(n - 1, nums) << endl;
        vector<int> dpPickNotPick(n, -1);
        cout << "Using pick-notpick algorithm: " << fPickNotPick(n - 1, nums, dpPickNotPick) << endl;
    }

    return 0;
}