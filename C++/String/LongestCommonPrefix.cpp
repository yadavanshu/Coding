#include<bits/stdc++.h>
using namespace std;

string LongestCommonPrefix(vector<string> strs){
    int len = INT_MAX;

    for_each(strs.begin(), strs.end(), [&](string str){
        if(len>str.size())
            len = str.size(); 
        });
    string ans = "";
    for (int i = 0; i < len;i++){
        bool flag = false;
        for (int j = 1; j < strs.size();j++){
            if(strs[0][i]==strs[j][i]){
                flag = true;
            }else{
                flag = false;
            }
        }
        if(flag){
            ans += strs[0][i];
        }
    }
    return ans;
}
string LongestCommonPrefix1(vector<string> strs){
    string ans = strs[0];
    for (int i = 1; i < strs.size();i++){
        int j = 0;
        while(j<strs[i].size() && j<ans.size() && strs[i][j]==ans[j]){
            j++;
        }
        ans = ans.substr(0, j);
    }
    return ans;
}
string LongestCommonPrefix2(vector<string> strs){
    if(strs.size()==0)
        return "";
    string ans = strs[0];
    for (int i = 1; i < strs.size();i++){
        while(strs[i].find(ans)!=0){
            ans = ans.substr(0, ans.size()-1);
        }
    }
    return ans;
}

string LongestCommonPrefix3(vector<string> strs){
    string ans = "";
    if(strs.size() == 0)
        return ans;
    for(int i = 0; i < strs[0].size(); i++){
        for(int j = 1; j < strs.size(); j++){
            if(i == strs[j].size() || strs[0][i] != strs[j][i]){
                return ans;
            }
        }
        ans += strs[0][i];
    }
    return ans;
}

int main(){
    vector<string> strs = {"flower","flower"};

    string ans = LongestCommonPrefix(strs);
    cout << ans;

    return 0;
}