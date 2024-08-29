
#include<bits/stdc++.h>

using namespace std;

class Solution{
public:	
    int firstOccurence(int arr[], int n ,int x);
    int lastOccurence(int arr[], int n ,int x);
	int count(int arr[], int n, int x) {
	    // code here
        if(lastOccurence(arr,n,x)==-1 || firstOccurence(arr,n,x)==-1)
            return 0;
        int ans = lastOccurence(arr,n,x) - firstOccurence(arr,n,x) + 1;
        return ans;
	}
};
int Solution::firstOccurence(int arr[], int n ,int x){
    int l=0, r=n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(arr[m]>x){
            r=m-1;
        }else if(arr[m]<x){
            l=m+1;
        }else{
            if(m==0 || arr[m]!=arr[m-1])
                return m;
            else
                r=m-1;
        }
    }
    return -1;
}
int Solution::lastOccurence(int arr[], int n ,int x){
    int l=0, r=n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(arr[m]>x){
            r=m-1;
        }else if(arr[m]<x){
            l=m+1;
        }else{
            if(m==(n-1) || arr[m]!=arr[m+1])
                return m;
            else
                l=m+1;
        }
    }
    return -1;
}
int main() {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    return 0;
}