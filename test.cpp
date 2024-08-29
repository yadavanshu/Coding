#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    nums.push_back(12);
    nums.push_back(13);
    nums.push_back(14);
    nums.push_back(15);
    nums.push_back(16);
    nums.push_back(17);
    nums.push_back(18);
    nums.push_back(19);

    for(auto xt:nums)
        cout << xt << " ";
    cout << endl;
    nums.push_back(100);
    int value = 100;

    int n = nums.size();
    swap(nums[n - 1], nums[n - 2]);
    for (int i = n - 2; i >= (n / 2);i--)
        swap(nums[i], nums[i - 1]);

    for (auto xt : nums)
        cout << xt << " ";

    return 0;
}