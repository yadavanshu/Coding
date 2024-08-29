#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> nums, int target){
    int n = nums.size();
    int low = 0, high = n - 1;
    if(nums[0]>target)
        return -1;
    while(low<=high){
        int mid = (high+low) / 2;
        if(nums[mid]==target)
            return nums[mid];
        else if(nums[mid]>target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return nums[high];
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 21, 25};
    int target = 0;
    cout << lowerBound(nums, target);
    return 0;
}