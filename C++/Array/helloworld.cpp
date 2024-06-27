#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Hello!!, World";
    vector<int> nums = {12,12,32,14,53};
    cout<<endl;
    for(auto xt:nums)
        cout<<xt<<" ";
    string str = "123456f9898";
    stringstream ss(str);
    int num;
    char x;
    int xt;
    ss >> num >> x>> xt;
    cout << num << " " << x<< " "<<xt;
    return 0;
}