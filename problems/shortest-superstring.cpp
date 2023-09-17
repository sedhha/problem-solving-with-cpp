#include <iostream>
#include <string>
#include <vector>
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

string computeSmallestSubStringFromSuperStrings(vector<string> words)
{
    int size = words.size();
    if (size == 0)
        return "";
    string smallest = words[0];
    for (int i = 0; i < size; i++)
    {
        string curr = words[i];
        if (curr.size() < smallest.size())
            smallest = curr;
    }
    return smallest;
}

string joinAllWordsInVector(vector<string> words)
{
    string joinedWord = "";
    for (int i = 0; i < words.size(); i++)
    {
        joinedWord += words[i];
    }
    return joinedWord;
}

string recursivelyFindWords(vector<string> words,
                            string currentWord,
                            int pos,
                            int lastPos,
                            unordered_map<int, vector<string>> map)
{
    if (pos == lastPos)
        return computeSmallestSubStringFromSuperStrings(map[lastPos]);

    string result = joinAllWordsInVector(words);
    for (int i = 0; i < words.size(); i++)
    {
        string superString = maxOverlappingString(currentWord, words[i]);
        int currKey = pos | (1 << i);
        map[currKey].push_back(superString);
        string nthResult = recursivelyFindWords(
            words,
            superString,
            currKey,
            lastPos,
            map);
        if (result.size() > nthResult.size())
            result = nthResult;
    }
    return result;
}

string shortestSuperString(vector<string> words)
{
    int size = words.size();
    if (size == 0)
        return "";
    if (size == 1)
        return words[0];

    int lastPos = (1 << size) - 1;
    string result = joinAllWordsInVector(words);
    unordered_map<int, vector<string>> map;
    for (int i = 0; i < size; i++)
    {
        int currPos = 1 << (i + 1);
        string nthResult = recursivelyFindWords(words, words[i], currPos, lastPos, map);
        if (result.size() > nthResult.size())
            result = nthResult;
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../ouput.txt", "w", stdout);

#endif
    int n;
    cin >> n;
    vector<string> words(n);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        words[i] = input;
    }
    cout << "Combined String = " << shortestSuperString(words) << endl;

    return 0;
}