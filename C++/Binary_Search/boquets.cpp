#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &flowers,int m, int k, int n,int i)
{
    int count = 0;
    int boquet = 0;
    for (int j = 0; j < n; j++)
    {
        if (flowers[j] <= i)
        {
            count++;
        }
        else
        {
            boquet += (count / k);
            count = 0;
        }
    }
    if (count != 0)
    {
        boquet += (count / k);
        count = 0;
    }
    if (boquet >= m)
        return true;
    else
        return false;
}
int roseGarden(vector<int> &flowers, int m, int k,int n)
{
    int minDays = *min_element(flowers.begin(), flowers.end());
    int maxDays = *max_element(flowers.begin(), flowers.end());
    long long check = (long long)m * (long long)k;
    if (check > flowers.size())
    {
        return -1;
    }
    int ans = -1;
    while(minDays<=maxDays){
        int mid = (minDays + maxDays) / 2;
        if(possible(flowers,m,k,n,mid)){
            ans = mid;
            maxDays = mid - 1;
        }else{
            minDays = mid + 1;
        }
    }
    return ans;
}
// int roseGarden(vector<int> &flowers, int m, int k,int n)
// {
//     int minDays = *min_element(flowers.begin(), flowers.end());
//     int maxDays = *max_element(flowers.begin(), flowers.end());

//     if (m * k > flowers.size())
//     {
//         return -1;
//     }
//     int ans = -1;
//     for (int i = minDays; i <= maxDays; i++)
//     {
//         if(possible(flowers,m,k,n,i)){
//             return i;
//         }
//     }
//     return ans;
// }


int main()
{
    int n;
    cin >> n;
    vector<int> flowers;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        flowers.push_back(t);
    }
    int m, k;
    cin >> m >> k;
    cout << roseGarden(flowers, m, k,n);

    return 0;
}