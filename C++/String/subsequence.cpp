#include<bits/stdc++.h>
using namespace std;

bool subSequence1(string &str, string &pat){
    int i = 0, n = str.length();
    int j = 0, m = pat.length();

    while(i<n && j<m){
        if(str[i]==pat[j]){
            i++;
            j++;
        }else{
            i++;
        }
        if(j==m)
            return true;
    }

    return false;
}

bool subSequence2(string &str, string &pat, int i, int j){
    if(j==pat.size())
        return true;
    if(i==str.size())
        return false;
    if(str[i]==pat[j])
        return subSequence2(str, pat, i + 1, j + 1);
    else
        return subSequence2(str, pat, i + 1, j);
}

int main()
{
    string str,pat;
    getline(cin, str);
    getline(cin, pat);
    if(subSequence2(str,pat,0,0))
        cout << "true";
    else
        cout << "false";
    return 0;
}