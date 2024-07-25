#include<bits/stdc++.h>
using namespace std;

class Bank{
    string name;
    public:
        void setName(string name){
            this->name = name;
        }
        virtual void getName(){
            cout << "Bank: " << name<<endl;
        }
};
class SBI:public Bank{
    public:
    void setName(string name){
        Bank::setName(name);
    }
    void getName() override{
        cout << "In SBI ";
        Bank::getName();
    }
};

class HDFC:public Bank{
    public:
    void setName(string name){
        Bank::setName(name);
    }
    void getName() override{
        cout << "In HDFC ";
        Bank::getName();
    }
};

int main(){
    Bank* sbi = new SBI();
    Bank* hdfc = new HDFC();
    sbi->setName("SBI");
    sbi->getName();
    hdfc->setName("HDFC");
    hdfc->getName();
    return 0;
}