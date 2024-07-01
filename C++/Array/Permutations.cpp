#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            ans.push_back(nums);
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution obj;
     vector<vector<int>> ans = obj.permute(nums);
    for(auto xt:ans){
        for(auto x:xt)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}