#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses1(string str)
    {
        int count = 0;
        string ans = "";
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
                count++;
            if (str[i] == ')')
                count--;

            if (count >= 2 && str[i] == '(')
                ans += str[i];
            if (count >= 1 && str[i] == ')')
                ans += str[i];
        }
        return ans;
    }
    string removeOuterParentheses2(string str)
    {
        int count = 0;
        string ans = "";
        int n = str.length();
        auto lambda = [&](char c)
        {
            if (c == '(')
                count++;
            else if (c == ')')
                count--;
            if (count >= 2 && c == '(')
                ans += c;
            else if (count >= 1 && c == ')')
                ans += c;
        };
        for_each(str.begin(), str.end(), lambda);
        return ans;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution obj;
    cout << obj.removeOuterParentheses2(str);

    return 0;
}