#include <iostream>
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

vector<int> getDecodedVector(vector<int> num, int first)
{
    int size = num.size();
    vector<int> actual;
    actual.push_back(first);
    for (int i = 1; i < size + 1; i++)
    {
        cout<<first<<" XOR "<<num[i-1]<<endl;
        actual.push_back(first ^ num[i - 1]);
        first = num[i];
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