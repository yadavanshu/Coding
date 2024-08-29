#include<bits/stdc++.h>
using namespace std;

int hoarePartition(vector<int> nums,int l,int h){
    int pivot = nums[l];
    int i = l - 1, j = h + 1;
    while(true){
        do{
            i++;
        } while (nums[i] < pivot);
        do{
            j--;
        } while (nums[j] > pivot);
        if(i>=j)
            return j;
        swap(nums[i], nums[j]);
    }
}

void quicksortHoare(vector<int> &nums,int l,int h){
    if(l<h){
        int p = hoarePartition(nums, l, h);
        quicksortHoare(nums, l, p);
        quicksortHoare(nums, p + 1, h);
    }
}

int lomutopartition(vector<int> &nums,int l, int h){
    int pivot = nums[h];
    int i = l - 1;
    for (int j = l; j <= h-1;j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[h]);
    return i+1;
}

void quicksortLomuto(vector<int> &nums,int l,int h){
    if(l<h){
        int p=lomutopartition(nums,l,h);
        quicksortLomuto(nums, l, p - 1);
        quicksortLomuto(nums, p + 1, h);
    }
}

void print(vector<int> &nums){
    for(auto xt:nums)
        cout << xt << " ";
    cout << endl;
}
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0;i<n;i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
        quicksortHoare(nums, 0, nums.size() - 1);
    print(nums);
    return 0;
}