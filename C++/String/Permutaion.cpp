#include<bits/stdc++.h>
using namespace std;

void Permuation(string &str){
    while(next_permutation(str.begin(),str.end()))
        cout<<str<< " ";
}

int main(){
    string str;
    cin>>str;
    Permuation(str);
    return 0;
}   