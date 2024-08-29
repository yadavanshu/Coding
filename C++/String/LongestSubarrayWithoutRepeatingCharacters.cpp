#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans=0;
    int start = 0, end = 0;
    int n = s.length();
    set<char> st;
    while(end<n){
        if(st.find(s[end])==st.end()){
            st.insert(s[end]);
            end++;
        }else{
            ans = max(ans, end-start);
            st.erase(s[start]);
            start++;
        }
    }
    ans = max(ans, end - start);
    return ans;
}

int main(){
    string str;
    getline(cin, str);
    cout << lengthOfLongestSubstring(str);

    return 0;
}