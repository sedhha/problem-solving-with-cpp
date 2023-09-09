#include <iostream>
#include <vector>
using namespace std;

void updateSumArray(vector<int> &sumArr, int num)
{
    for (int i = 0; i < 32; i++)
    {
        int ithBit = num & (1 << i);
        if (ithBit)
            sumArr[i]++;
    }
}

int computeNumFromBinaryBits(vector<int> nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
        result += nums[i] * (1 << i);
    return result;
}

void uniqueNumberThree(vector<int> nums)
{
    vector<int> sumArr(32, 0); // An integer holds max upto 32 bits
    for (int num : nums)
    {
        updateSumArray(sumArr, num);
    }
    for (int i = 0; i < 32; i++)
    {
        sumArr[i] = sumArr[i] % 3;
    }
    cout << "The number is " << computeNumFromBinaryBits(sumArr) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

#endif

    int size, num;
    cin >> size;
    vector<int> nums(size, 0);

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        nums[i] = num;
    }
    uniqueNumberThree(nums);
}