/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void subsequencesum(int i,vector<int> &ds, int s,int sum,vector<int> arr,int n){
    if(i==n){
        if(s==sum){
            for(auto xt:ds)
                cout<<xt<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    sum+=arr[i];
    subsequencesum(i+1,ds,s,sum,arr,n);
    
    sum-=arr[i];
    ds.pop_back();
    subsequencesum(i+1,ds,s,sum,arr,n);
    
}
bool subsequencesum1(int i,vector<int> &ds, int s,int sum,vector<int> arr,int n){
    if(i==n){
        if(s==sum){
            for(auto xt:ds)
                cout<<xt<<" ";
            cout<<endl;
            return true;
        }
        else return false;;
    }
    ds.push_back(arr[i]);
    sum+=arr[i];
    if(subsequencesum1(i+1,ds,s,sum,arr,n)==true) return true;
    
    sum-=arr[i];
    ds.pop_back();
    if(subsequencesum1(i+1,ds,s,sum,arr,n)==true) return true;
    return false; 
}
int subsequencesum2(int i, int s,int sum,vector<int> arr,int n){
    if(i==n){
        if(s==sum){
            return 1;
        }
        else return 0;;
    }
    sum+=arr[i];
    int left=subsequencesum2(i+1,s,sum,arr,n);
    
    sum-=arr[i];
    int right=subsequencesum2(i+1,s,sum,arr,n);
    return left+right; 
}

int main()
{
    cout<<"Hello World  ";
    cout<<endl;
    vector<int> arr={1,2,3,4,5};
    int n=arr.size();
    for(auto xt: arr)
        cout<<xt<<" ";
    cout<<endl;
    vector<int> ds;
    int s=5;
    subsequencesum(0,ds,s,0,arr,n);
    
    subsequencesum1(0,ds,s,0,arr,n);
    cout<<"Total: "<<subsequencesum2(0,s,0,arr,n);
    return 0;
}
