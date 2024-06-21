#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // time - limit exceeded
    // int smallestDivisor(vector<int>& nums, int threshold) {
    //     int low = 1, high = *max_element(nums.begin(),nums.end());
    //     int ans = INT_MAX;
    //     for(low = 1;low<=high;low++){
    //         int sum = 0;
    //         for(auto xt:nums){
    //             sum += ceil(xt/(double)low);
    //         }
    //         if(sum <= threshold)
    //             ans = min(ans,low);
    //     }
    //     return ans;
    // }
    bool checkDivisor(vector<int>& nums, int threshold, int divisor){
        int sum = 0;
        int res = -1;
        for(auto xt:nums){
            sum += ceil(xt / (double)divisor);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(low<=high){
            int divisor = (low + high) / 2;
            if (checkDivisor(nums, threshold, divisor))
            {
                ans = divisor;
                high = divisor - 1;
            }
            else
            {
                low = divisor + 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums;
    int n;
    cin>> n;
    int threshold;
    cin>>threshold;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        nums.push_back(t);
    }
    Solution obj;
    cout<<obj.smallestDivisor(nums,threshold);

    return 0;
}