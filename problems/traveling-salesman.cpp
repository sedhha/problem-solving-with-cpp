#include <iostream>
#include <cmath>
using namespace std;

int shortestPath(vector<vector<int> > nums, int visited, int current, vector<vector<int> > &visitedRecord)
{
    int size = nums.size();
    if (visited == (1 << size) - 1)
    {
        // We're already at the last city and so we need to
        // return the distance of this city from Home
        return nums[current][0];
    }
    if (visitedRecord[visited][current] != -1)
        return visitedRecord[visited][current];

    int ans = INT_MAX;
    for (int cityChoice = 0; cityChoice < size; cityChoice++)
    {
        int cityToGoTo = 1 << cityChoice;
        bool alreadyVisited = visited & cityToGoTo;
        if (!alreadyVisited)
        {
            int distanceForSubSet = nums[current][cityChoice] + shortestPath(nums, visited | (1 << cityChoice), cityChoice, visitedRecord);
            ans = min(ans, distanceForSubSet);
        }
    }
    visitedRecord[visited][current] = ans;
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
    vector<vector<int> > visitedRecord(1 << n, vector<int>(n, -1));
    cout << "Min Distance = " << shortestPath(nums, 1, 0, visitedRecord) << endl;
}