#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper2(vector<string> &ans, string store, int n, int open, int close)
    {
        if (store.size() == 2 * n)
        {
            ans.push_back(store);
            return;
        }
        if (open < n)
        {
            store.push_back('(');
            helper2(ans, store, n, open + 1, close);
            store.pop_back();
        }
        if (close < open)
        {
            store.push_back(')');
            helper2(ans, store, n, open, close + 1);
            store.pop_back();
        }
    }
    vector<string> generateParenthesis2(int n)
    {
        vector<string> ans;
        string store;
        helper2(ans, store, n, 0, 0);
        return ans;
    }
    void helper1(vector<string> &ans, string store, int n, int open, int close)
    {
        if (store.size() == 2 * n)
        {
            ans.push_back(store);
            return;
        }
        if (open < n)
        {
            store.push_back('(');
            helper1(ans, store, n, open + 1, close);
            store.pop_back();
        }
        if (close < open)
        {
            store.push_back(')');
            helper1(ans, store, n, open, close + 1);
            store.pop_back();
        }
    }
    vector<string> generateParenthesis1(int n)
    {
        vector<string> ans;
        string store;
        helper1(ans, store, n, 0, 0);
        return ans;
    }
};



int main(){
    int n;
    cin >> n;
    Solution obj;
    vector<string> ans = obj.generateParenthesis2(n);
    for(auto xt:ans){
        cout << xt << " ";
    }
    return 0;
}