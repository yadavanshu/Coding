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
    int speedbs(vector<int>& piles, int rate){
        int reqH = 0;
        for(auto xt: piles){
            reqH += ceil((double)(xt)/(double)(rate));            
        }
        return reqH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int rate = (low + high)/2;
            int totalH= speedbs(piles,rate);
            if(totalH<=h){
                high = rate - 1;
            }else{
                low = rate + 1;
            }
        }
        return low;
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