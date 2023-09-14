#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
    For every word, combine it with every other word
    and memoize the result:
    abcd bcd cde bcda
    1    1   1   1
    For abcd:
    with bcd: 1100 => [abcd, ]
    with cde: 1010 => [abcde, ]
    with bcda: 1001 => [abcda, ]

    For bcd:
    with abcd: 1100 => [abcd, bcdabcd, ]
    with cde: 0110 => [bcde]
    with bcda: 0101 => [bcda]

    For cde:
    with abcd: 1010 => [abcde, cdeabcd, ]
    with bcd: 0110 => [bcde, cdebcd]
    with bcda: 0011 => [cdebcda]

    For bcda:
    with abcd: 1001 => [abcda, bcdabcd],
    with bcd: 0101 => [bcdabcd, bcda]
    with cde: 0011 => [cdebcda, bcdacde]

    Combining:
    1100 => [abcd, bcdabcd, ]
    1010 => [abcde, cdeabcd, ]
    1001 => [abcda, bcdabcd, ]
    0110 => [bcde, cdebcd]
    0011 => [cdebcda, bcdacde]
    0101 => [bcdabcd, bcda]

    Combining Results:

    1110: [
        abcdabcde,
        abcdcdeabcd,
        bcdabcdabcde,
        bcdabcdeabcd
    ],
    1101: [
        abcdabcda,
        bcdabcdabcda,

    ]

    // Two for loops:
    Generate first set of possibilities



*/

string overlappingWord(string s1, string s2)
{
    int s1Size = s1.size();
    int s2Size = s2.size();
    if (s2Size > s1Size)
        return s1 + s2;

    int s1StartPointer = 0;
    int s2StartPointer = 0;
    while (s1StartPointer < s1Size && s2StartPointer < s2Size)
    {
        char s1Char = s1[s1StartPointer];
        char s2Char = s2[s2StartPointer];
    }
}
string smallestSuperString(int current, string smallestSuperString,
                           vector<string> words,
                           vector<vector<string>> dp)
{
    int size = words.size();

    for (int i = 0; i < size; i++)
    {
        string firstWord = words[i];
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                continue;
            string secondWord = words[j];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../ouput.txt", "w", stdout);

#endif
    int n;
    cin >> n;

    return 0;
}