#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> sortPeople1(vector<string> &names, vector<int> &heights)
    {
        unordered_map<int, string> mp;
        vector<string> res;
        for (int i = 0; i < names.size(); i++)
            mp[heights[i]] = names[i];
        sort(heights.begin(), heights.end(), greater<int>());
        for (int i = 0; i < heights.size(); i++)
            res.push_back(mp[heights[i]]);
        return res;
    }
    vector<string> sortPeople2(vector<string> &names, vector<int> &heights)
    {
        vector<pair<string, int>> test;
        vector<string> res;
        for (int i = 0; i < names.size(); i++)
        {
            test.push_back({names[i], heights[i]});
        }
        auto lambda = [&](pair<string, int> m, pair<string, int> n)
        {
            return m.second > n.second;
        };
        sort(test.begin(), test.end(), lambda);
        for (auto xt:test)
            res.push_back(xt.first);
        return res;
    }

    vector<string> sortPeople3(vector<string> &names, vector<int> &heights)
    {
        int n = heights.size();
        vector<pair<int, string>> p(n);
        for (int i = 0; i < n; i++)
        {
            p[i].first = heights[i];
            p[i].second = names[i];
        }
        sort(p.begin(), p.end());
        vector<string> ans;
        for (auto xt : p)
            ans.push_back(xt.second);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution solution;
    int n;

    cin >> n;
    vector<string> names(n);
    vector<int> heights(n);

    for (int i = 0; i < n; i++)
        cin >> names[i];

    for (int i = 0; i < n; i++)
        cin >> heights[i];

    vector<string> result = solution.sortPeople3(names, heights);

    for (const string &name : result)
        cout << name << " ";
    cout << endl;

    return 0;
}