#include<bits/stdc++.h>
using namespace std;

bool anagram(string &str, string &pat){
    vector<int> alphabet(26, 0);
    for(auto xt:str)
        alphabet[xt - 'a']++;
    for(auto xt:pat)
        alphabet[xt - 'a']--;
    for(auto xt:alphabet)
        if(xt > 0)
            return false;
    return true;
}
int main()
{
    string str, pat;
    getline(cin, str);
    getline(cin, pat);
    if (anagram(str, pat))
        cout << "true";
    else
        cout << "false";
    return 0;
}