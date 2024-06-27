#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string complexNumberMultiply1(string num1, string num2)
    {
        stringstream ss1(num1), ss2(num2);
        int real1, real2, imag1, imag2;
        char extra;
        ss1 >> real1 >> extra >> imag1 >> extra;
        ss2 >> real2 >> extra >> imag2 >> extra;
        string ans;

        ans = to_string((real1 * real2) - (imag1 * imag2));
        ans += '+';
        ans += to_string((real1 * imag2) + (imag1 * real2));
        ans += 'i';
        return ans;
    }
    string complexNumberMultiply2(string num1, string num2)
    {
        stringstream ss1(num1), ss2(num2);
        int real1, real2, imag1, imag2;
        char extra;
        ss1 >> real1 >> extra >> imag1 >> extra;
        ss2 >> real2 >> extra >> imag2 >> extra;
        string ans;
        stringstream ssans;

        ssans << ((real1 * real2) - (imag1 * imag2));
        ssans << '+';
        ssans << ((real1 * imag2) + (imag1 * real2));
        ssans << 'i';
        ans = ssans.str();
        // string word;
        // while (ssans >> word)
        //     ans += word;
        return ans;
    }
};

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    Solution obj;
    cout << obj.complexNumberMultiply2(num1, num2);
    return 0;
}