#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        int count = 0;
        stringstream ss(s);
        string token;
        string ans = "";
        while (ss >> token)
        {
            ans += token + " ";
            count++;
            if (count == k)
                break;
        }
        return ans.substr(0, ans.size() - 1);
    }
};

int main(){
    string str;
    getline(cin, str);
    int k;
    cin >> k;
    Solution obj;
    cout << obj.truncateSentence(str, k);
    return 0;
}