#include<bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int> nums, vector<vector<int>> &ans, vector<int> test,int i = 0){
    if(i==nums.size()){
        ans.push_back(test);
        return;
    }
    generateSubsets(nums, ans, test, i + 1);
    test.push_back(nums[i]);
    generateSubsets(nums, ans, test, i + 1);
    test.pop_back();
}
auto lambda = [&](vector<int> x, vector<int> y){
    if (x.size() == y.size())
        return x < y;
    return x.size() < y.size();
};

int main(){
    vector<int> nums = {1, 2, 3, 4};

    vector<vector<int>> ans;
    vector<int> test;
    generateSubsets(nums, ans,test, 0);
    

    sort(ans.begin(), ans.end(),lambda);
    for(auto xt:ans){
        for(auto x:xt){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}