#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int num1 = INT_MAX, num2 = INT_MAX;
        for (auto xt : nums){
            if (xt <= num1)
                num1 = xt;
            else if (xt <= num2)
                num2 = xt;
            else
                return true;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 2, 3, 4};
    Solution obj;
    if(obj.increasingTriplet(nums))
        cout << "True -> Present";
    else
        cout << "False -> Absent";
    return 0;
}