#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s){
        stack<char> st;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(')
                st.push(s[i]);
            else{
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
    bool isValid2(string s){
        int count = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i]=='(')
                count++;
            else
                count--;
            if(count<0)
                return false;
        }
        return count == 0;
    }
    void helper2(vector<string> &ans, string store, int n){
        if (store.size() == 2 * n){
            if(isValid(store))
                ans.push_back(store);
            return;
        }
        helper2(ans, store + "(", n);
        helper2(ans, store + ")", n);
    }
    vector<string> generateParenthesis2(int n){
        vector<string> ans;
        string store;
        helper2(ans, store, n);
        return ans;
    }
    void helper1(vector<string> &ans, string store, int n, int open, int close){
        if (store.size() == 2 * n){
            ans.push_back(store);
            return;
        }
        if (open < n){
            store.push_back('(');
            helper1(ans, store, n, open + 1, close);
            store.pop_back();
        }
        if (close < open){
            store.push_back(')');
            helper1(ans, store, n, open, close + 1);
            store.pop_back();
        }
    }
    vector<string> generateParenthesis1(int n){
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