#include<bits/stdc++.h>
using namespace std;

void rearrange_neg_pos(vector<int> &nums){
    int n=nums.size();
    vector<int> pos,neg;
    for(int i=0;i<n;i++){
        if(nums[i]>0)
            pos.push_back(nums[i]);
        else
            neg.push_back(nums[i]);
    }

    if(pos.size()<neg.size()){
        for(int i=0;i<pos.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=2*pos.size();
        for(int i=pos.size();i<neg.size();i++)
            nums[index++]=neg[i];
    }else{
        for(int i=0;i<neg.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=2*neg.size();
        for(int i=neg.size();i<pos.size();i++)
            nums[index++]=pos[i];
        
    }
}

int main(){
    vector<int> nums={1,-2,-4,5,6,7,8,9,-5,-6,10,29,23};
    for(auto xt:nums)
        cout<<xt<<" ";
    cout<<endl;
    rearrange_neg_pos(nums);
    for(auto xt:nums)
        cout<<xt<<" ";

}