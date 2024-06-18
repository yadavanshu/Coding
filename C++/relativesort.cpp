#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr2.size();i++)
            mp[arr2[i]] = i;
        
        for(auto &xt:arr1){
            if(!mp.count(xt))
                mp[xt]=1e9;
        }
        auto lambda = [&](int num1,int num2){
            if(mp[num1]==mp[num2])
                return num1<num2;
            return mp[num1]<mp[num2];
        };


        sort(begin(arr1),end(arr1),lambda);

        return arr1;
    }
};

int main(){
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    Solution obj;
    vector<int> ans;
    ans = obj.relativeSortArray(arr1,arr2);
    for(auto xt: ans)
        cout<<xt<<" ";

    return 0;
}