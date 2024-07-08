#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b==c || b+c==a || a+c==b)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }

    return 0;
}
