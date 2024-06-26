#include<bits/stdc++.h>
using namespace std;

int happyNeighbourhood(vector<int> &house, int m){
    int ans = 0;
    if(m==1)
        return 1;
    int n = house.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n;i++){
        visited[house[i]-1] = true;
        int count = 0;
        for(auto xt:visited){
            if(xt == true){
                count++;
                if(count==m)
                    return i+1;
            }else{
                count = 0;
            }
        }
    }

        return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> house;
    
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        house.push_back(x);
    }
    cout << happyNeighbourhood(house, m);

    return 0;
}