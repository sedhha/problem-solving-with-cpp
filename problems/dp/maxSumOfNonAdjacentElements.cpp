#include <iostream>

using namespace std;

/*
    Example:

*/

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

    return 0;
}