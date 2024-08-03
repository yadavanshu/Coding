#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){
        map<char, char> mps;
        map<char, char> mpt;
        if (s.size() != t.size())
            return false;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if ((mps.find(s[i]) != mps.end() && mps[s[i]] != t[i]) ||
                (mpt.find(t[i]) != mpt.end() && mpt[t[i]] != s[i]))
                return false;
            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }
        return true;
    }
};
int main(){
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.isIsomorphic(s, t) << endl;
    return 0;
}