#include<bits/stdc++.h>
using namespace std;

class Bank{
    string name;
    public:
        Bank(const string &name) : name(name){};
        virtual void getName(){
            cout << "Bank: " << name;
            cout << endl;
        }
};
class SBI:public Bank{
    public:
        SBI(const string &name) : Bank(name) {};
        void getName() override{
            cout << "In SBI: ";
            Bank::getName();
            cout << endl;
        }
};
class HDFC:public Bank{
    public:
        HDFC(const string &name) : Bank(name) {};
        void getName() override{
            cout << "In HDFC: ";
            Bank::getName();
            cout << endl;
        }
};

int main(){
    Bank *sbi = new SBI("SBI Mumbai");
    Bank *hdfc = new HDFC("HDFC Lucknow");
    SBI *sbibank = new SBI("sbibank");
    HDFC *hdfcbank = new HDFC("hdfcbank");
    sbi->getName();
    hdfc->getName();
    sbibank->getName();
    hdfcbank->getName();

    return 0;
}