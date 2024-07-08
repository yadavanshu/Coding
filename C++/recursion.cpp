/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
void name(int i,int n){
    if(i>n)
        return;
    else
    {    
        cout<<i<<" HELLO   ";
        name(++i,n);
    }
}

void n1ton(int n){
    if(n==0) return;
    n1ton(n-1);
    cout<<n<<" ";
}
void nto1(int n){
    if(n==0) return;
    cout<<n<<" ";
    nto1(n-1);
}
int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}
void reverse(vector<int> &arr,int l,int r){
    if(l>=r) return;
    swap(arr[l],arr[r]);
    reverse(arr,l+1,r-1);
}

bool palindrome(string str,int i,int j){
    cout<<" "<<i<<str[i]<<" "<<j<<str[j];
    if(i>j) return true;
    if(str[i]!=str[j])
        return false;
    
    return palindrome(str,i+1,j-1);
}

int fibonacci(int n){
    if(n<=1) return n;
    
    return (fibonacci(n-1) + fibonacci(n-2));
}
void subset(string s,string curr,int i=0){
    if(i==s.length()){
        cout<<curr<<" ";
        return;
    }
    subset(s,curr,i+1);
    subset(s,curr+s[i],i+1);
}


int main()
{
    cout<<"Hello World  ";
    name(1,10);
    cout<<endl;
    n1ton(10);
    cout<<endl;
    nto1(10);
    cout<<endl;
    cout<<sum(5);
    cout<<endl;
    cout<<fact(10);
    cout<<endl;
    vector<int> arr={1,2,3,4,5};
    reverse(arr,0,4);
    for(auto xt: arr)
        cout<<xt<<" ";
    cout<<endl;
    string str="aabbaaa";
    (palindrome(str,0,6))?cout<<"Palindrome":cout<<"NOT PALInDROME";
    cout<<endl;
    int x=fibonacci(2);
    cout<<x;
    
    cout<<endl;
    subset("abc","");

    return 0;
}
