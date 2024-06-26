#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        string ans;
        int i;
        int n = num.size();
        for (i = n - 1; i >= 0; i--)
        {
            int x = (int)(num[i] - '0');
            if (x % 2 == 1)
            {
                break;
            }
        }
        return num.substr(0, i + 1);
    }
};



int main(){
    string str;
    cin >> str;
    Solution obj;
    cout<<obj.largestOddNumber(str);
    return 0;
}