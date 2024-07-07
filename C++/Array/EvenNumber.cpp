// An array is given 12 239 7 8 8756 123
// output: 2 --> 12, 8759
//return the count of digits with even length


#include<bits/stdc++.h>
using namespace std;

int countEvenDigits(vector<int> nums){
    int count = 0;
    for(auto xt:nums){
        int tmp = floor(log10(xt)) + 1;
        // cout << tmp<<" ";
        if(tmp%2==0)
            count++;
    }
    return count;
}


int main(){
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << countEvenDigits(nums);

    return 0;
}