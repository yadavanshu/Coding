
#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

int lower_bound(int v[],int n, int x){
    if(v[0]>x) return -1;
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(v[m]==x){
                return v[m];
            }else if(v[m]>x)
                r=m-1;
            else l=m+1;                
        }
        return v[r];
}
int upper_bound(int v[],int n, int x){
    if(v[n-1]<x) return -1;
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(v[m]==x){
                return v[m];
            }else if(v[m]>x)
                r=m-1;
            else l=m+1;                
        }
        return v[l];
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    pair<int,int> p;
    p.first = lower_bound(arr,n,x);
    p.second = upper_bound(arr,n,x);
    return p;
}