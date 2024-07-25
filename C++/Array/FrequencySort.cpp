#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> frequencySort2(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto xt : nums)
            mp[xt]++;
        auto lambda = [&](int x, int y)
        {
            if (mp[x] == mp[y])
                return x > y;
            return mp[x] < mp[y];
        };
        sort(nums.begin(), nums.end(), lambda);
        return nums;
    }

    static bool mycmp(pair<int, int> i, pair<int, int> j)
    {
        return (i.second == j.second) ? i.first > j.first : i.second < j.second;
    }
    vector<int> frequencySort1(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        vector<pair<int, int>> ans;
        for (auto xt : mp)
            ans.push_back(xt);
        vector<int> res;

        sort(ans.begin(), ans.end(), mycmp);
        for (auto xt : ans)
            for (int i = 0; i < xt.second; i++)
                res.push_back(xt.first);

        return res;
    }
};

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    vector<int> ans;
    Solution obj;
    ans = obj.frequencySort2(nums);
    for (auto xt : ans)
        cout << xt << " ";
    return 0;
}