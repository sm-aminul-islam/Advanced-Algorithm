#include<bits/stdc++.h>
using namespace std;
bool SubsetSum(vector<int>&ar,int n,int x)
{
    vector<vector<bool>>DP(n+1,vector<bool>(x+1,0));
    DP[0][0]=1;



    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=x; j++)
        {
            DP[i][j]=DP[i-1][j];
            if(j-ar[i-1]>=0)
            {
               DP[i][j]  = (DP[i][j] or DP[i-1][j-ar[i-1]]);

            }
        }
    }


    return DP[n][x];
}

int main ()
{
    int n,x;
    cin>>n>>x;
    vector<int> ar(n);
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    cout<<SubsetSum(ar,n,x)<<"\n"<<endl;
}
