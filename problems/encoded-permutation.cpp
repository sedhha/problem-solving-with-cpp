#include <iostream>
#include <vector>
using namespace std;

vector<int> decode(vector<int> encoded)
{
    int first = 1;
    int size = encoded.size();
    vector<int> result(size + 1, 0);
    result[0] = first;

    for (int i = 0; i < size; i++)
    {
        result[i + 1] = first ^ encoded[i];
        first = result[i + 1];
    }
    return result;
}

void printVector(vector<int> result)
{
    int size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

#endif
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    printVector(nums);
    vector<int> result(n + 1, 0);
    result = decode(nums);
    printVector(result);

    return 0;
}