#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum =0;
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi = max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }

int main(){
    vector<int> nums = {4, 3, 1, 5, 6};
    cout<<"max subarray: "<<maxSubArray(nums);
    return 0;
}