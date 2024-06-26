#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0;
        int ans = 0;
        for (auto xt : s)
        {
            if (xt == '(')
                count++;
            if (xt == ')')
            {
                ans = max(count, ans);
                count--;
            }
        }
        return ans;
    }
};

int main(){
    string str;
    getline(cin, str);
    Solution obj;
    cout<<obj.maxDepth(str);

    return 0;
}