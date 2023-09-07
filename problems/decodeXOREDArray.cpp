#include <iostream>
#include <vector>
using namespace std;

void printNum(int addr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << addr[i] << " ";
    }
}

void printVector(vector<int> number)
{
    for (int i = 0; i < number.size(); i++)
    {
        cout << number[i] << ", ";
    }
}

vector<int> getDecodedVector(vector<int> encoded, int first)
{
    int size = encoded.size();
    vector<int> actual;
    actual.push_back(first);
    for (int i = 0; i < size; i++)
    {
        int xoredNum = first ^ encoded[i];
        actual.push_back(xoredNum);
        first = xoredNum;
    }
    return actual;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    /*
     */

    int size;
    int first;
    cin >> size >> first;
    int number[size];
    for (int i = 0; i < size; i++)
        cin >> number[i];
    vector<int> nums(number, *(&number + 1));
    vector<int> decodedVector = getDecodedVector(nums, first);
    printVector(decodedVector);
    return 0;
}