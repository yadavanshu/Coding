#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
        {
            k = k % n;
            reverse(nums.begin() + (n - k), nums.end());
            reverse(nums.begin(), nums.begin() + (n - k));
            reverse(nums.begin(), nums.end());
        }
        else
        {
            reverse(nums.begin() + (n - k), nums.end());
            reverse(nums.begin(), nums.begin() + (n - k));
            reverse(nums.begin(), nums.end());
        }
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    obj.rotate(nums, 3);
    for (auto xt : nums)
        cout << xt << " ";
    return 0;
}