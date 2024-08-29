#include <iostream>
#include <stdexcept>
using namespace std;

int divide(int a, int b)
{
    if (b == 0)
    {
        throw invalid_argument("Division by zero");
    }
    return a / b;
}

int main()
{
    int x = 10;
    int y = 0;
    try
    {
        int result = divide(x, y);
        cout << "Result: " << result << endl;
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
