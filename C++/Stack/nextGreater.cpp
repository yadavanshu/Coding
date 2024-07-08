#include<bits/stdc++.h>
using namespace std;

void previousGreater(vector<int> arr){
    stack<int> st;
    int n=arr.size();
    st.push(arr[n-1]);
    cout<<-1<<" ";
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
        int ans=st.empty()?-1:st.top();
        cout<<ans<<" ";
        st.push(arr[i]);
    }
}


int main()
{
    cout<<"hello world!!";
    cout<<endl;
    vector<int> arr={12,3,4,15,17,19,2,21,9,15,0,9};
    for(auto xt:arr)
        cout<<xt<<" ";
    cout<<endl;
    previousGreater(arr);
    return 0;
}
