#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string token;
        s = "";
        while(ss>>token){
            s = token + " " + s;
        }
        return s.substr(0,s.size()-1);
    }
};

int main(){

    string str;
    getline(cin, str);
    Solution obj;
    cout<<obj.reverseWords(str);

    return 0;
}