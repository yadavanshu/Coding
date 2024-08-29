#include<bits/stdc++.h>
using namespace std;

//why we use virtual in destructor
// A virtual destructor is used in C++ to ensure that the derived class's destructor is called when an object is deleted through a base class pointer. This is crucial for proper resource cleanup and avoiding resource leaks in polymorphic scenarios. Without a virtual destructor, only the base class destructor is called, potentially leaving resources allocated by the derived class unreleased.

class Bank{
    public:
    Bank(){
        cout << "In Bank"<<endl;
    }
    ~Bank(){
        cout << "Bank Object Destroyed" << endl;
    }
};

class RBI{
    public:
    RBI(){
        cout << "In RBI" << endl;
    }

    ~RBI(){
        cout << "RBI Object Destroyed" << endl;
    }
};

class SBI : public RBI, public Bank{
    public:
    SBI(){
        cout << "In SBI" << endl;
    }

    ~SBI(){
        cout << "SBI Object Destroyed" << endl;
    }
};


int main(){
    Bank sbi;
    // SBI sbi1;
    return 0;
}