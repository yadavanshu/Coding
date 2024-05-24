# Adjacent Stick Game

Mukesh and friends have set out on a vacation to Coorg. They have booked accommodation in a resort and the resort authorities organize Camp fires every night as a part of their daily activities. Mukesh volunteered himself for an activity called the "Adjacent Stick Game" where sticks of different length will be placed in a line and Mukesh needs to remove a stick from each adjacent pair of sticks. He then has to form a bigger stick by combining all the remaining sticks.

Mukesh needs to know the smallest length of the bigger stick so formed and needs your help to compute the same. Given the number of sticks N and the lengths of each of the sticks, write a program to find the smallest length of the bigger stick that is formed.

#### Input format :
First line of input contains an integer N denoting the number of sticks. Assume that the maximum value for N as 50.
<br>
Assume that N is always even.
<br>
Next line of input contains an N integer denoting the length of each of the sticks.

#### Output format :
Output the smallest length of the bigger stick that is formed.

**Sample test cases :<br>
Input 1 :<br>**
4<br>
2 1 3 1<br>
**Output 1 :<br>**
2

**Input 2 :<br>**
4<br>
4 2 3 5<br>
**Output 2 :<br>**
5


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
```cpp
#include<iostream>
using namespace std;
int main()
{
    int n,i,j=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i=i+2)
    {
        if(a[i]<a[i+1])
        {
            j=j+a[i];
        }
        else
        {
            j=j+a[i+1];
        }
    }
    cout<<j;
    return 0;
}

```
