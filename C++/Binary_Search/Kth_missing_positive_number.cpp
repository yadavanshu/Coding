#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &nums, int k)
    {
        for (auto xt:nums){
            if(xt<=k)
                k++;
            else
                break;
        }
        return k;
    }
};

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    Solution obj;
    cout << obj.findKthPositive(nums, k);
    return 0;
}