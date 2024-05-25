#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &nums){
    int maxi=INT_MIN;
    for(auto xt:nums)
        if(xt>maxi)
            maxi=xt;
    int maxis=INT_MIN;
    for(auto xt:nums)
        if(xt<maxi && xt>maxis)
            maxis = xt;
    return maxis;
}

int main(){
    vector<int> nums = {12,2,45,7,9,98,1,10,32,91};
    cout<<"Second Largest: "<<secondLargest(nums);
    return 0;
}