#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void printVector(vector<string> words)
{
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << " ";
    cout << endl;
}

string overlappingWord(string s1, string s2)
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
            s2Pointer = 0;
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
bool isIthIndexVisited(int currentState, int i)
{
    int shiftedNumber = (1 << i);
    int result = currentState & shiftedNumber;
    return result != 0;
}

string shortestStringInGivenVector(vector<string> words)
{
    int size = words.size();
    if (size == 0)
        return "";
    string shortest = words[0];
    for (int i = 1; i < size; i++)
        if (words[i].size() < shortest.size())
            shortest = words[i];
    return shortest;
}
void generateComboForGivenWord(
    string currentWord,
    vector<string> words,
    int vectorSize,
    int finalState,
    int coveredState,
    vector<string> &mergedWords)
{
    if (coveredState >= finalState)
    {
        mergedWords.push_back(currentWord);
        return;
    }
    for (int i = 0; i < vectorSize; i++)
    {
        bool isNodeVisited = isIthIndexVisited(coveredState, i);
        if (!isNodeVisited)
        {
            string superstring = overlappingWord(currentWord, words[i]);
            int newState = coveredState | (1 << i);
            generateComboForGivenWord(superstring, words, vectorSize, finalState, newState, mergedWords);
        }
    }
    return;
}
string shortestSuperstring(
    vector<string> words)
{
    int size = words.size();
    int finalState = (1 << size) - 1;
    vector<string> mergedWords;
    for (int i = 0; i < size; i++)
    {
        string currentWord = words[i];
        generateComboForGivenWord(
            currentWord,
            words,
            size,
            finalState,
            1 << i,
            mergedWords);
    }
    string shortestCombination = shortestStringInGivenVector(mergedWords);
    return shortestCombination;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

#endif
    int n;
    cin >> n;

    vector<string> words(n, "");
    for (int i = 0; i < n; i++)
        cin >> words[i];

    string result = shortestSuperstring(words);
    cout << result << endl;
    // vector<string> mergedWords;
    // generateComboForGivenWord("gcta", words, words.size(), ((n << 1) - 1), 1, mergedWords);
    // printVector(mergedWords);
    // cout << overlappingWord("abc", "bxadef");
    return 0;
}