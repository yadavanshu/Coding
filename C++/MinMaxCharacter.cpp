#include<bits/stdc++.h>
using namespace std;

void minmaxcharacter(string str){
    map<char,int> mp;
    pair<char,int>p[2];
    for(int i=0;i<str.length();i++)
        mp[(str[i])]++;
    int maxi=INT_MIN,mini=INT_MAX;
    for(auto xt:mp){
        if(maxi<xt.second && xt.first!=' '){
            maxi=xt.second;
            p[0].first=xt.first;
            p[0].second=xt.second;
        }
        if(mini>xt.second){
            mini=xt.second;
            p[1].first=xt.first;
            p[1].second=xt.second;
        }
    }
    for(auto xt:mp){
        cout<<xt.first<<" "<<xt.second;
        cout<<endl;
    }
    cout<<"Max: "<<p[0].first<<" "<<p[0].second<<" Mini: "<<p[1].first<<" "<<p[1].second;
}



int main(){
    string str="hello my name is King Ronin Saitma Rengoku Natsu DDDDDDDDDDDDDDDDDDDDDragneelyyyyyyyyyyyyyyyyyyyyyyyyyyyyy Igneel Valorant Omen cccccccccccccchutchutchutchutchutchutcchutchutchutchutchutchutcgik";
    minmaxcharacter(str);
    return 0;
}