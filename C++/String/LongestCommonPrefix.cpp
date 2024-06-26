#include<bits/stdc++.h>
using namespace std;

string LongestCommonPrefix(vector<string> strs,string mini){

    for (int i = 0; i < mini.size();i++){
        string temp = mini[i];
        for (int j = 0; j < strs.size();j++){
            if()
        }
    }
}

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    sort(strs.begin(), strs.end(),[&](string s,string t){
        return s.size() < t.size();});
    string mini = strs[0];
    cout << mini;
    return 0;
}