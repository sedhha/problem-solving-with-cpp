#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string maxOverlappingString(string s1, string s2)
{
    int s1Size = s1.size();
    int s2Size = s2.size();
    int s1Pointer = 0;
    int s2Pointer = 0;
    int pos = 0;
    while (s1Pointer < s1Size && s2Pointer < s2Size)
    {
        if (s1[s1Pointer] != s2[s2Pointer])
        {
            pos = 0;
            s1Pointer++;
        }
        else if (s1[s1Pointer] == s2[s2Pointer])
        {
            pos = s2Pointer + 1;
            s1Pointer++;
            s2Pointer++;
        }
    }
    return s1 + s2.substr(pos, s2Size);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../ouput.txt", "w", stdout);

#endif
    string s1, s2;
    cin >> s1 >> s2;

    cout << "Max overlapping string = " << maxOverlappingString(s1, s2) << endl;

    return 0;
}