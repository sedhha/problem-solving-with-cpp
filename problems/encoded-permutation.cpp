#include <iostream>
#include <vector>
using namespace std;

vector<int> decode(vector<int> encoded) {
    int n = encoded.size() + 1;
    int total_xor = 0, even_xor = 0;
    for (int i = 1; i <= n; ++i) {
        total_xor ^= i;
    }
    for (int i = 1; i < n - 1; i += 2) {
        even_xor ^= encoded[i];
    }
    
    vector<int> perm(n, 0);
    perm[0] = total_xor ^ even_xor;
    
    for (int i = 0; i < n - 1; ++i) {
        perm[i + 1] = perm[i] ^ encoded[i];
    }
    
    return perm;
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