#include <bits/stdc++.h>
using namespace std;

void calculate(int x)
{
    cout << "one " << x / 10 << endl;
}
void calculate(int x, int y)
{
    cout << "two " << x / y << endl;
}

void calculate(double x, int y)
{
    cout << "three "<<(x / y) << endl;
}

int fun(int x){
    return x;
}
double fun(int x){
    static_cast<double>(x);
    return x;
}

int main()
{
    // calculate(100);
    // calculate(100, 100);
    // calculate(100.0, 100);

    cout << fun(2);
    cout <<fixed<<setprecision(2)<< fun(2.0);
    return 0;   
}