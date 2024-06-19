#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int count = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==majority){
                count++;
            }else{
                count--;
            }
            if(count==0){
                majority=nums[i];
                count=1;
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(majority==nums[i])
                count++;

        }
        if(count<= n/2)
            return -1;

        return majority;
    }
    void print(vector<int> const &nums){
        // for(auto xt:nums)
        //     cout<<xt<<" ";
        for_each(nums.begin(),nums.end(),[](int x){cout<<x<<" ";});
        cout<<endl;
    }
};

int main(){
    int n;
    cin>> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        nums.emplace_back(tmp);
    }   
    Solution obj;
    obj.print(nums);
    int ans= obj.majorityElement(nums);
    cout<<"Majority Element: "<<ans;

    return 0;
}