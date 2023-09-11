#include <iostream>
#include <cmath>
using namespace std;

int shortestPath(vector<vector<int> > nums, int visited, int current)
{
    int size = nums.size();
    if (visited == (1 << size) - 1)
    {
        // We're already at the last city and so we need to
        // return the distance of this city from Home
        return nums[current][0];
    }

    int ans = INT_MAX;
    for (int cityChoice = 0; cityChoice < size; cityChoice++)
    {
        int cityToGoTo = 1 << cityChoice;
        bool alreadyVisited = visited & cityToGoTo;
        if (!alreadyVisited)
        {
            int distanceForSubSet = nums[current][cityChoice] + shortestPath(nums, visited | (1 << cityChoice), cityChoice);
            ans = min(ans, distanceForSubSet);
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

#endif
    int n;
    cin >> n;
    vector<vector<int> > nums(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];
    cout << "Min Distance = " << shortestPath(nums, 1, 0) << endl;
}