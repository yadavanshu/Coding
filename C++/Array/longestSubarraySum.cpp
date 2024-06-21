#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int lenOfLongSubarr(int arr[],  int n, int k) 
    // { 
    //     int len=0,sum=0;
    //     for(int i=0;i<n;i++){
    //         sum=0;
    //         bool flag=false;
    //         for(int j=i;j<n;j++){
    //             sum=sum+arr[j];
                
    //             if(sum==k) len=max(len,(j-i+1));
    //         }
    //     }
    //     return len;
    // } 

    int lenOfLongSubarr(int arr[], int n, int k){
        map<int,int> mp;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int rem = sum - k;
            if(sum == k) ans = max(ans , i+1 );
            if(mp.find(rem)!=mp.end()){
                int len = i - mp[rem];
                ans = max(ans,len);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return ans;
    }

};

int main() {
	
	int t;
    cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
    }
	return 0;
}