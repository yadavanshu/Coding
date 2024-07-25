#include <iostream>
#include <string>
using namespace std;

class Bank
{
    string name;
    string branchCode;
    string location;
    double phoneNo;

public:
    Bank(const string &name, const string &branchCode, const string &location, const double &phoneNo)
        : name(name), branchCode(branchCode), location(location), phoneNo(phoneNo) {}

    virtual ~Bank()
    {
        cout << name << " Object Destroyed" << endl;
    }

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Branch Code: " << branchCode << endl;
        cout << "Location: " << location << endl;
        cout << "Phone No.: " << phoneNo << endl;
    }
};

class SBI : public Bank
{
public:
    SBI(const string &name, const string &branchCode, const string &location, const double &phoneNo)
        : Bank(name, branchCode, location, phoneNo) {}

    void display() override
    {
        cout << "SBI Bank:" << endl;
        Bank::display();
    }
};

class HDFC : public Bank
{
public:
    HDFC(const string &name, const string &branchCode, const string &location, const double &phoneNo)
        : Bank(name, branchCode, location, phoneNo) {}

    void display() override
    {
        cout << "HDFC Bank:" << endl;
        Bank::display();
    }
};

int main()
{

    SBI sbi("SBI Main Branch", "SBI001", "Mumbai", 1234567890);
    HDFC hdfc("HDFC Corporate Office", "HDFC002", "Delhi", 9876543210);

    sbi.display();
    hdfc.display();

    return 0;
}
