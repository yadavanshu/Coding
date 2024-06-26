#include<bits/stdc++.h>
using namespace std;

int NaivePatternSearching(string str,string pat){
    int n = str.length();
    int m = pat.length();
    int i = 0, j = 0;
    while(i<n){
        if(str[i]==pat[j]){
            i++;
            j++;
        }else{
            i++;
            j = 0;
        }
        if(j==m-1){
            return i - m+1;
        }
    }

    return -1;
}


int main(){
    string str;
    string pat;
    getline(cin, str);
    getline(cin, pat);
    cout << NaivePatternSearching(str,pat);

        
    return 0;
}