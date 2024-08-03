#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool palindrome(string str){
        string temp = str;
        int i = 0;
        int j = str.size() - 1;
        while (i<j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome1(string s){
        int n = s.length();
        int maxi = 0;
        string ans;
        for (int i = 0; i < n;i++){
            for (int j = i+1; j <= n;j++){
                string test = s.substr(i,j-i);
                if (palindrome(test) && test.size() > maxi){                
                    ans = test;
                    maxi = test.size();
                }
            }
        }
        return ans;
    }
    bool helper(string s, int i,int j){
        if(i>=j)
            return true;
        if(s[i]!=s[j])
            return false;
        return helper(s, i + 1, j - 1);
    }
    string longestPalindrome2(string s){
            int n = s.length();
            int maxi = 0;
            string ans;
            for (int i = 0; i < n;i++){
                for (int j = i+1; j <= n;j++){
                    string test = s.substr(i,j-i);
                    if (helper(test,0,test.size()-1) && test.size() > maxi){
                        ans = test;
                        maxi = test.size();
                    }
                }
            }
            return ans;
    }

};

int main()
{
    string str;
    getline(cin, str);
    Solution obj;
    cout << obj.longestPalindrome1(str);
    cout << endl;
    cout << obj.longestPalindrome2(str);
    return 0;
}