#include <bits/stdc++.h>
using namespace std;

void reverseWord1(string &str)
{
    int start = 0;
    int n = str.size();
    while (str[n - 1] == ' ')
        n--;
    while (str[start] == ' ')
        start++;
    for (int end = start; end < n; end++)
    {
        if (str[end] == ' ')
        {
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
    }
    reverse(str.begin() + start, str.end());
    reverse(str.begin(), str.end());
}

void reverseWord2(string &str)
{
    stack<string> words;
    string word = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            if (word.size() >= 1)
            {
                words.push(word);
                word = "";
            }
        }
        else
        {
            word += str[i];
        }
    }

    words.push(word);
    str = "";
    while (!words.empty())
    {
        str += words.top();
        if (!words.empty())
            str += " ";
        words.pop();
    }
}
void reverseWord3(string &str)
{
    stringstream ss(str);
    string ans = "";
    string token = "";
    while (ss >> token)
    {
        ans = token + " " + ans;
    }
    str = ans.substr(0, ans.size() - 1);
}

void reverseWord4(string &str)
{
    int n = str.size();
    int start = 0, end = 0;
    int i = 0;
    reverse(str.begin(), str.end());
    while (i < n)
    {
        while (i < n && str[i] != ' ')
            str[end++] = str[i++];

        if (start < end)
        {
            reverse(str.begin() + start, str.begin() + end);
            str[end] = ' ';
            end++;
            start = end;
        }
        i++;
    }
    str=str.substr(0,end-1);
}

int main()
{
    string str;
    getline(cin, str);

    reverseWord4(str);
    cout << str;

    return 0;
}