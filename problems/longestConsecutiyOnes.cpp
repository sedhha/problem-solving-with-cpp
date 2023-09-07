#include <iostream>
using namespace std;

int solve(int n)
{
    int longestOneStreak = 0;
    int currentStreak = 0;
    while (n > 0)
    {
        int currentLastBit = n & 1;
        if (currentLastBit == 1)
            currentStreak++;
        else
        {
            if (longestOneStreak < currentStreak)
                longestOneStreak = currentStreak;
            currentStreak = 0;
        }
        n = n >> 1;
    }
    return longestOneStreak;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << solve(n) << endl;
}