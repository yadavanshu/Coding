#include <bits/stdc++.h>
using namespace std;

void setMatrix1(vector<vector<int>> &mat)
{
    vector<bool> row(mat.size(), false), col(mat[0].size(), false);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (row[i] || col[j])
            {
                mat[i][j] = 0;
            }
        }
    }
}
void setMatrix(vector<vector<int>> &mat)
{
    vector<bool> row(mat.size(), false), col(mat[0].size(), false);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < mat.size(); i++)
    {
        if (row[i])
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < mat[0].size(); i++)
    {
        if (col[i])
        {
            for (int j = 0; j < mat.size(); j++)
            {
                mat[j][i] = 0;
            }
        }
    }
}

void setMatrix2(vector<vector<int>> &mat){
    // int row[mat.size()] --> mat[...][0]
    // int col[mat[0].size()] ---> mat[0][...]
    int col0=1;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                mat[i][0]=0;
                if(j!=0)
                    mat[0][j]=0;
                else
                    col0=0;
            }
        }
    }
    for(int i=1;i<m;i++){
        if(mat[i][0]==0){
            for(int i=1;)
        }
    }


}

int main()
{
    vector<vector<int>> mat(5, vector<int>(5, 1));
    mat[2][1] = 0;
    mat[0][3] = 0;
    cout<<"--------\n";
    for (auto xt : mat)
    {
        for (auto x : xt)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    // setMatrix(mat);
    setMatrix1(mat);
    cout<<"--------\n";
    for (auto xt : mat)
    {
        for (auto x : xt)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}