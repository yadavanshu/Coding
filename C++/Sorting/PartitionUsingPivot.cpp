#include<bits/stdc++.h>
using namespace std;

vector<int> partition(vector<int> &nums, int pivot){
    vector<int> ans(nums.size());
    int l = 0, h = nums.size() - 1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<pivot){
            ans[l++] = nums[i];
        }else{
            ans[h--] = nums[i];
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    int n;
    int pivot;
    cin >> n>>pivot;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    vector<int> ans= partition(nums, pivot);
    for(auto xt:ans)
        cout << xt << " ";
        return 0;
}