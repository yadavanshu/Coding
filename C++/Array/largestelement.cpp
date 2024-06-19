#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> const &nums){
    int maxi=INT_MIN;
    for(auto xt:nums)
        if(xt>maxi)
            maxi = xt;
    return maxi;
}

int main(){
    vector<int> nums = {12,2,45,7,9,98,1,10,32,91};
    cout<<"Largest: "<<largestElement(nums);
    return 0;
}