#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs){
    map<string, vector<string>> mp;
    for(auto xt:strs){
        string sorted = xt;
        sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(xt);
    }
    vector<vector<string>> ans;
    for(auto xt:mp){
        ans.push_back(xt.second);
    }
    return ans;
}

int main(){
    vector<string> strs;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        string str;
        cin >> str;
        strs.push_back(str);
    }

    auto ans = groupAnagrams(strs);
    for(auto xt:ans){
        for(auto x:xt){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}