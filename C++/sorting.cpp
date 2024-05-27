#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> nums);
void selectionsort(vector<int> nums);
void mergesorting(vector<int> nums);
void bubblesort(vector<int> nums);
void print(vector<int> &nums);



int main(){
    vector<int> nums={45,12,3,1,65,9,10,75,42,23,29,80};
    cout<<"Before Sorting: ";
    print(nums);
    bubblesort(nums);
    selectionsort(nums);
    insertionsort(nums);
    mergesorting(nums);
    return 0;
}

void print(vector<int> &nums){
    for(auto xt:nums)
        cout<<xt<<" ";
    cout<<endl;
}


//-----------Bubble Sort-----------------
void bubblesort(vector<int> nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=i;j<n;j++){
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
                flag=true;
            }
        }
        if(!flag) break;
    }
    cout<<"After Bubble Sort: ";
    for(auto xt:nums)
        cout<<xt<<" ";
    cout<<endl;
}


//-----------Selection Sort--------------
void selectionsort(vector<int> nums){
    int min_idx=0;
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        min_idx=i;
        for(int j=i;j<n;j++){
            if(nums[j]<nums[min_idx])
                min_idx=j;
        }
        swap(nums[min_idx],nums[i]);
    }
    cout<<"After Selection Sort: ";
    for(auto xt:nums)
        cout<<xt<<" ";
    cout<<endl;
}


//--------Insertion Sort--------------
void insertionsort(vector<int> nums){
    int n=nums.size();
    int key=nums[0];
    int j=0;

    for(int i=1;i<n;i++){
        key=nums[i];
        j=i-1;
        while(j>=0 && nums[j]>key){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
    cout<<"After Insertion Sort: ";
    for(auto xt:nums)
        cout<<xt<<" ";
    cout<<endl;
}   



// ----------Merge Sort----------
void merge(vector<int> &nums,int low,int mid,int high){
    int l=mid-low + 1, r = high - mid;
    vector<int> left(l);
    vector<int> right(r);
    for(int i=0;i<l;i++)
        left[i]=nums[i+low];
    for(int i=0;i<r;i++)
        right[i]=nums[i+mid+1];
    int i=0,j=0,k=low;
    while(i<l && j<r){
        if(left[i]<right[j]){
            nums[k]=left[i];
            k++;
            i++;
        }else{
            nums[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<l){
        nums[k]=left[i];
        i++;
        k++;
    }
    while(j<r){
        nums[k]=right[j];
        j++;
        k++;
    }    

}

void mergesort(vector<int> &nums,int low,int high){
    if(low<high){
        int mid=low + (high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
}

void mergesorting(vector<int> nums){
    mergesort(nums,0,nums.size()-1);
    cout<<"After Merge Sorting: ";
    for(auto xt:nums)
        cout<<xt<<" ";
    cout<<endl;
}