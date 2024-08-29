#include<bits/stdc++.h>
using namespace std;

bool isUnique(string str){
    int n = str.length();
    unordered_set<char> s;
    for (int i = 0; i < n;i++){
        if(s.find(str[i])!=s.end())
            return false;
        s.insert(str[i]);
    }
    return true;
}

string longestSubstring(string str){
    int n = str.size();
    string ans;
    int maxi = 0;
    for (int i = 0; i <n;i++){
        for (int j = 0; j <=i;j++){
            string test = str.substr(j,i-j+1);
            // cout << test<<" ";
            if(isUnique(test) && test.size()>maxi){
                ans = test;
                maxi = test.size();
            }
        }
    }
    return ans;
}

int longestSubstring2(string str){
    int n = str.size();
    int maxi = 0;
    int start = 0, end = 0;
    set<char> st;
    while(end<n){
        if(st.find(str[end])==st.end()){
            st.insert(str[end]);
            end++;
            maxi = max(maxi, end - start);
        }else{
            st.erase(str[start]);
            start++;
        }
    }
    maxi = max(maxi, end - start);
    return maxi;
}







int main(){
    string str;
    getline(cin, str);
    cout << longestSubstring(str)<<" "<<longestSubstring2(str);

    return 0;
}