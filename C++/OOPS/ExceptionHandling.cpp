#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,2,3};
    int index = 7;
    try
    {
        if(index >= arr.size())
            throw "Index out of bounds";
        cout << arr[index] << endl;
    }
    catch (const char *e)
    {
        cout<<"Error: " << e << '\n';
    }
    
    return 0;
}