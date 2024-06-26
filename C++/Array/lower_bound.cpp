#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        // Your code here
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(v[m]==x){
                ans=m;
                return ans;
            }else if(v[m]>x)
                r=m-1;
            else l=m+1;                
        }
        return r;
    }
};

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}