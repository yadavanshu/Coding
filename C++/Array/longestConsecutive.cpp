#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums){
    int len=1;
    int n=nums.size();
    int ans=1;
    unordered_set<int> st(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        int tmp=nums[i];
        len=1;
        if(st.find(tmp-1)==st.end()){
            while(st.find(tmp+1)!=st.end()){
                len++;
                tmp+=1;
            }
            ans = max(ans,len);
        }
    }
    return ans;
}

int longestConsecutiveSet(vector<int> &nums){
    int longest=1;
    int n=nums.size();
    int curr=1;
    unordered_set<int> st(nums.begin(),nums.end());
    for(auto xt:st){
        if(st.find(xt-1)==st.end()){
            int tmp=xt;
            int curr=1;
            while(st.find(tmp+1)!=st.end()){
                curr++;
                tmp+=1;
            }
            longest = max(curr,longest);
        }
    }
    return longest;
}

int longestConsecutiveSorting(vector<int> nums){
    sort(nums.begin(),nums.end());
    int longest=1;
    int n=nums.size();
    int currCount=0; 
    int lastsmaller = INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]-1 == lastsmaller){
            currCount++;
            lastsmaller=nums[i];
        }else if(nums[i]!=lastsmaller){
            currCount=1;
            lastsmaller=nums[i];
        }
        longest=max(longest,currCount);
    }
    return longest;
}

int main(){
    vector<int> nums={102,103,104,105,106,106,107,4,100,1,101,3,2,1,5,6,8,9,10};
    int len=longestConsecutive(nums);
    cout<<"Longest Consecutive: "<<len<<" \n";
    len=longestConsecutiveSorting(nums);
    cout<<"Longest Consecutive: "<<len<<" ";
    cout<<endl;
    len=longestConsecutiveSet(nums);
    cout<<"Longest Consecutive: "<<len<<" ";
    cout<<endl;
    return 0;
}