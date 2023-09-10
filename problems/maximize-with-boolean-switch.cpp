/*
    You are given an m x n binary matrix grid.

    A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

    Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

    Return the highest possible score after making any number of moves (including zero moves).

    Constraints:

    m == grid.length

    n == grid[i].length

    1 <= m, n <= 20

    grid[i][j] is either 0 or 1.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int matrixScore(vector<vector<int> > grid)
{
    // Maximize the row swaps
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++)
    {
        if (grid[i][0] == 0)
        {
            for (int j = 0; j < cols; j++)
                grid[i][j] ^= 1; // Logic to toggle 1s and 0s
        }
    }
    int sum = 0;
    // Contribution of first column to final score
    sum += rows * (1 << (cols - 1));
    for (int j = 1; j < cols; j++)
    {
        int count = 0;
        for (int i = 0; i < rows; i++)
            if (grid[i][j] == 1)
                count++;
            
        int colSum = max(count, rows - count) * (1 << (cols - j - 1));
        sum += colSum;
    }
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int m, n;
    cin >> n >> m;
    vector<vector<int> > nums(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            nums[i][j] = num;
        }
    cout << "Result = " << matrixScore(nums) << endl;
}