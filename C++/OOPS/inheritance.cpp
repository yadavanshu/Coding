#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        int a=10;
};
class B:virtual public A{
    public:
        int b=20;
};
class C:virtual public A{
    public:
        int c=30;
};
class D:public B,public C{
    public:
        int d=40;
};


int main(){
    D md;
    cout << md.a;
    cout << md.d;
    return 0;
}