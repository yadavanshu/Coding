/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

void stockspan(vector<int> arr){
    stack<int> st;
    st.push(0);
    int n=arr.size();
    cout<<1<<" ";
    for(int i=1;i<n;i++){
        while((st.empty()==false) && arr[st.top()]<=arr[i])
        {    st.pop();}
        int span=(st.empty())?(i+1):(i-st.top());
        cout<<span<<" ";
        st.push(i);
    }
}

int main()
{
    cout<<"hello world!!";
    cout<<endl;
    vector<int> arr={12,3,4,15,17,19,2,21,9,15,0,9};
    stockspan(arr);
    return 0;
}
