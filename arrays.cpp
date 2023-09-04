#include <iostream>
#include <array>
using namespace std;

void doubleArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= 2;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ",";
}

void printModernArray(array<int, 6> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ",";
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = {1, 2, 3, 4, 5};
    int sizeOfArray = sizeof(arr) / sizeof(int);
    doubleArray(arr, sizeOfArray);
    printArray(arr, sizeOfArray);
    cout << endl;
    array<int, 6> modernArray = {1, 2, 3, 4, 5, 6};
    printModernArray(modernArray);

    return 0;
}