#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxi = 0;
        for_each(nums.begin(), nums.end(), [&](int x)
                 { if(x<k) maxi=x; });
        return maxi;
    }
};
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    Solution obj;
    int ans = obj.maxFrequency(nums, k);
    cout << ans;
    return 0;
}