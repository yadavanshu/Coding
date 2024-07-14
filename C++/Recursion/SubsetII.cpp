#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helperBrute(vector<int> &nums, set<vector<int>> &st, vector<int> test,int i)
    {
        if (i == nums.size())
        {
            sort(test.begin(), test.end());
            st.insert(test);
            return;
        }
        helperBrute(nums, st, test, i + 1);
        test.push_back(nums[i]);
        helperBrute(nums, st, test, i + 1);
        test.pop_back();
    }
    void helper(vector<int> &nums, vector<vector<int>> &store, vector<int> test,int idx)
    {
        store.push_back(test);
        for (int i = idx; i < nums.size();i++){

            if(i!=idx && nums[i]==nums[i-1])
                continue;
            test.push_back(nums[i]);
            helper(nums, store, test, i + 1);
            test.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> test;
        vector<vector<int>> store;
        sort(nums.begin(), nums.end());
        helper(nums, store, test, 0);
        return store;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans;

    Solution obj;
    ans = obj.subsetsWithDup(nums);
    for (auto xt : ans)
    {
        for (auto x : xt)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}