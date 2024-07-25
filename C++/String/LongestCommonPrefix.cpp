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

int main(){
    vector<string> strs = {"flower","flower"};

    string ans = LongestCommonPrefix(strs);
    cout << ans;

    return 0;
}