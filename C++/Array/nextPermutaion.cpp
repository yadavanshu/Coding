#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums){
    next_permutation(nums.begin(),nums.end());
}

int main(){
    vector<int> nums={1,2,3};
    nextPermutation(nums);
    for(auto xt:nums)
        cout<<xt<<" ";
    return 0;
}