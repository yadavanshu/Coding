#include<bits/stdc++.h>
using namespace std;

void partition(vector<int> nums,int pivot){
    vector<int> ans;
    for (int i = 0; i < nums.size();i++)
        if(nums[i]<pivot)
            ans.push_back(nums[i]);

    


}

void print(vector<int> &nums){
    for(auto xt:nums)
        cout << xt << " ";
    cout << endl;
}
int main()
{
    vector<int> nums = {45, 12, 3, 1, 65, 9, 10, 75, 42, 23, 29, 80};
    cout << "Before Sorting: ";
    print(nums);
    return 0;
}