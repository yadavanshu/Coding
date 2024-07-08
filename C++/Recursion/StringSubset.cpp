#include <bits/stdc++.h>
using namespace std;

void generateSubset(string str, string ans, vector<string> &res, int i){
    if (i == str.size()){
        res.push_back(ans);
        return;
    }
    generateSubset(str, ans, res, i + 1);
    generateSubset(str, ans + str[i], res, i + 1);
}

int main()
{
    string str;
    getline(cin, str);
    vector<string> res;
    generateSubset(str, "", res, 0);
    for (auto xt : res)
        cout << xt << " ";

    return 0;
}