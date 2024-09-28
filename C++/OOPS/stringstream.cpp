#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Example of using stringstream for input
    string input = "123 45.67 hello";
    stringstream ss(input);
    int intValue;
    double doubleValue;
    string strValue;

    // Extract values from the stringstream
    ss >> intValue;      // Reads the integer
    ss >> doubleValue;   // Reads the double
    ss >> strValue;      // Reads the string

    // Output the extracted values
    cout << "Integer: " << intValue << endl;
    cout << "Double: " << doubleValue << endl;
    cout << "String: " << strValue << endl;

    // Example of using stringstream for output
    stringstream outputSS;
    outputSS << "Value of int: " << intValue << ", Value of double: " << doubleValue;
    string result = outputSS.str(); // Get the concatenated string

    cout << "Output String: " << result << endl;



    return 0;
}
