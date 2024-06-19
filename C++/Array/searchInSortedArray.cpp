#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
    }
};

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        nums.push_back(t);
    }

    int target;
    cin>>target;
    
    Solution obj;
    int ans = obj.search(nums,target);
    cout<<ans;
    return 0;
}