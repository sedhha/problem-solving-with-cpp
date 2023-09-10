#include <iostream>
#include <unordered_map>
using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    int result = left;
    for (int i = left + 1; i <= right; i++)
    {
        result &= i;
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int left, right;
    cin >> left >> right;

    int result = rangeBitwiseAnd(left, right);
    cout << result << endl;
    return 0;
}