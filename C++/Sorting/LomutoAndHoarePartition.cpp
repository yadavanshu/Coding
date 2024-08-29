#include<bits/stdc++.h>
using namespace std;

vector<int> lomutoPartition(vector<int> nums){
    int n = nums.size();
    int pivot = nums[n - 1];
    int i = - 1;
    // 12 11 10 7 5 4 3 2 6 9
    for (int j = 0; j <= n-2; j++){
        if (nums[j] < pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[n - 1]);
    return nums;
}
vector<int> hoarePartition(vector<int> nums){
    int n = nums.size();
    int pivot = nums[0];
    int i = -1, j = n;
    while(true){
        do{
            i++;
        } while (nums[i] < pivot);

        do{
            j--;
        } while (nums[j] > pivot);
        if(i>=j)
            break;
        swap(nums[i], nums[j]);
    }
    return nums;
}

int main(){
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    vector<int> ans = lomutoPartition(nums);
    for (auto xt : ans)
        cout << xt << " ";
    cout<<endl;
    ans = hoarePartition(nums);
    for (auto xt : ans)
        cout << xt << " ";
    return 0;
}