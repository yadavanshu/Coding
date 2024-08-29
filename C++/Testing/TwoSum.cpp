#include<bits/stdc++.h>
using namespace std;
int twoSum(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    sort(nums.begin(),nums.end());  
    while(i<j){
        int sum = nums[i] + nums[j];
        if(sum==target)
            return true;
        else if(sum<target)
            i++;
        else
            j--;
    }
    return false;
}

vector<pair<int,int>> twoSumPair(vector<int> nums,int target){
    vector<pair<int, int>> ans;
    int n = nums.size();
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            int sum = nums[i] + nums[j];
            if(sum==target)
                ans.push_back(make_pair(nums[i], nums[j]));
        }
    }
    return ans;
}

vector<pair<int,int>> twoSumPairLessThan(vector<int> nums,int target){
    vector<pair<int, int>> ans;
    int n = nums.size();
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            int sum = nums[i] + nums[j];
            if(sum<target)
                ans.push_back(make_pair(nums[i], nums[j]));
        }
    }
    return ans;
} 
vector<pair<int,int>> twoSumPairLessThanOptimized(vector<int> nums,int target){
    vector<pair<int, int>> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int i = 0, j = n - 1;
    while(i<j){
        int sum = nums[i] + nums[j];
        if(sum<target){
            for (int k = i+1; k <= j;k++){
                ans.push_back(make_pair(nums[i], nums[k]));
            }
            i++;
        }
        else{
            j--;
        }

    }
    return ans;
} 

int main(){
    int n,target;
    cin >> n >> target;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    if(twoSum(nums,target))
        cout << "True";
    else
        cout << "False";
    cout << endl;
    auto ans = twoSumPair(nums,target);
    for (auto xt : ans){
        cout << "(" << xt.first << ", " << xt.second << ") ";
    }
    cout<<"\nPairs less than target"<<endl;
    ans = twoSumPairLessThan(nums,target);
    for(auto xt:ans){
        cout<<"(" << xt.first << ", " << xt.second <<") ";
    }
    cout<<"\nPairs less than target Optimized"<<endl;
    ans = twoSumPairLessThanOptimized(nums,target);
    for(auto xt:ans){
        cout<<"(" << xt.first << ", " << xt.second <<") ";
    }
    return 0;
}