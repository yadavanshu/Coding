#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        return (s + s).find(goal) != string::npos;
    }
};


int main(){
    
    string s, goal;
    cin >> s >> goal;
    
    Solution obj;
    obj.rotateString(s, goal)?cout<<"True":cout<<"False";
    return 0;
}