#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> nums = {-1, 1, 1, 2, 3};
    int target = 2;
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = nums.size() - 1;
    int count = 0;
    int sum = 0;

    while (i < j){
        sum = nums[i] + nums[j];
        if (sum < target){
            count += j - i;
            i++;
        }
        else{
            j--;
        }
    }

    cout << endl<< "Count: " << count;
    return 0;
}
