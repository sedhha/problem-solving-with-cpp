#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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

string shortestSuperstring(vector<string> words)
{
    unordered_set<char> allWords;
    string combinedWord, resultString;
    for (int i = 0; i < words.size(); i++)
        combinedWord += words[i];

    for (int i = 0; i < combinedWord.size(); i++)
    {
        char key = combinedWord[i];
        bool exists = allWords.count(key);
        if (!exists)
            resultString += key;
        allWords.insert(key);
    }
    return resultString;
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
    cout << "Combined String = " << shortestSuperstring(words) << endl;

    return 0;
}