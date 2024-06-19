#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool capacity(vector<int> &weights, int days, int cap){
        int sum = 0;
        int k = 1;
        for(auto xt: weights){
            if(sum + xt > cap){
                k++;
                sum = 0;
            }
            sum += xt;
        }
        if(k <= days) return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans=low;
        while(low<=high){
            int cap = (low+high)/2;
            if(capacity(weights,days,cap)){
                ans = cap;
                high = cap - 1;
            }else{
                low = cap+1;
            }
        }
        return ans;
    }
};


int main(){
    vector<int> weights;
    int n;
    cin>> n;
    int days;
    cin>>days;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        weights.push_back(t);
    }
    Solution obj;
    cout<<obj.shipWithinDays(weights,days);

    return 0;
}