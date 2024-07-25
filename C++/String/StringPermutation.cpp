#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool match(string st, string tt, vector<int> mst)
    {
        vector<int> mtt(26, 0);
        for (auto xt : tt)
            mtt[xt - 'a']++;
        for (int i = 0; i < 26; i++)
            if (mst[i] != mtt[i])
                return false;
        return true;
    }
    bool checkInclusion(string s, string t)
    {
        vector<int> mst(26, 0);
        for (auto xt : s)
            mst[xt - 'a']++;
        int m = t.size();
        int n = s.size();
        if (n > m)
            return false;

        for (int i = 0; i <= t.size() - n; i++)
        {
            string test = t.substr(i, n);
            if (match(s, test, mst))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s = "ab";
    string t = "eidbaooo";
    cout << (sol.checkInclusion(s, t) ? "true" : "false") << endl;
    return 0;
}