#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string input;
    cin >> input;
    int output = -1;
    unordered_map<char,int> map;
    for (char x : input) {
        bool valueExists = map.count(x) == 1;
        if(valueExists) map[x] += map[x];
        else map[x] = 1;
    }
    for(int i = 0; i < input.size(); i++) {
        if(map[input[i]] == 1) {
            output = i;
            break;
        }
    }
    cout<<output<<endl;
    
    return 0;
}