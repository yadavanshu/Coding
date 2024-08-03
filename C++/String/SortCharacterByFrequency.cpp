#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort1(string str){
        vector<pair<char,int>> pr;
        unordered_map<char, int> mp;

        for(auto xt:str)
            mp[xt]++;
        for(auto xt:mp)
            pr.push_back({xt.first, xt.second});

        auto lambda = [&](pair<char, int> m, pair<char, int> n) {
            if(m.second==n.second)
                return m.first < n.first;
            return m.second > n.second;
        };
        sort(pr.begin(), pr.end(), lambda);
        str = "";
        for(auto xt:pr)
            while(xt.second--)
                str += xt.first;
        return str;
    }
    string frequencySort2(string str)
    {
        map<char, int> mp;
        for_each(str.begin(), str.end(), [&](char ch)
                { mp[ch]++; });

        auto lambda = [&](char c, char s){
            if(mp[c]==mp[s])
                return c < s;
            return mp[c] > mp[s] ;
        };
        sort(str.begin(), str.end(),lambda);
        return str;
    }
    string frequencySort3(string str)
    {
        string ans = "";
        int freq[256] = {0};
        
        for (int i = 0; i < str.length(); i++){
            char ch = str[i];
            freq[ch]++;
        }

        vector<pair<int, char>> freqVec;
        for (int i = 0; i < 256; i++)
            if (freq[i] > 0)
                freqVec.push_back({freq[i], char(i)});

        sort(freqVec.begin(), freqVec.end(), [](pair<int, char> a, pair<int, char> b)
             {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first; });

        for (auto &p : freqVec)
            ans.append(p.first, p.second);

        return ans;
    }
};

int main(){
    string str;
    getline(cin, str);
    Solution obj;
    cout << obj.frequencySort3(str);

    return 0;
}