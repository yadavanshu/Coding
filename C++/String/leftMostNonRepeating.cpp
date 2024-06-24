#include <bits/stdc++.h>
using namespace std;

int leftMostRepeating(string &str)
{
    vector<int> alphabet(26, 0);
    for (int i = 0; i < str.size(); i++)
        alphabet[str[i] - 'a']++;
    for (int i = 0; i < str.size(); i++)
        if (alphabet[str[i] - 'a'] == 1)
            return i;
    return -1;
}
int main()
{
    string str;
    getline(cin, str);
    int ans = leftMostRepeating(str);
    if (ans == -1)
        cout << -1;
    else
        cout << str[ans];
    return 0;
}