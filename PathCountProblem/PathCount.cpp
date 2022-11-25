#include<bits/stdc++.h>
using namespace std;

int PathCount(int n,int m){
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;

        }
    }
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
 for(int i=0;i<m;i++)
    {
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]= (dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]);

        }
    }
    return dp[n-1][m-1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<"Path Count :" <<PathCount(n,m)<<" ";

    return 0;
}
