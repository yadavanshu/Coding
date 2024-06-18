#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool speed(vector<int>& piles, int h, int rate){
    //     int sum = 0;
    //     int reqH = 0;
    //     for(auto xt: piles){
    //         sum = xt;
            
    //         while(sum>0){
    //             sum = sum - rate;
    //             reqH++;
    //         }
    //     }
    //     if(reqH <= h)
    //         return true;
    //     return false;

    // }
    bool speedbs(vector<int>& piles,int h, int rate){
        long long reqH = 0;
        for(auto xt: piles){
            reqH +=ceil((double)(xt) / rate);           
        }
        return reqH<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int ans = -1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int rate = (low + high)/2;
            if(speedbs(piles,h,rate)){
                ans = rate;
                high = rate - 1;
            }else{
                low = rate + 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> weights;
    int n;
    cin>> n;
    int hours;
    cin>>hours;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        weights.push_back(t);
    }
    Solution obj;
    cout<<obj.minEatingSpeed(weights,hours);
    return 0;
}