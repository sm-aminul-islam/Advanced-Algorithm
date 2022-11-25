#include<bits/stdc++.h>
using namespace std;

int  Minimum_Cost_Path(int n,int m, int **grid)
{
    int dp[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dp[i][j]=0;
        }
    }

    dp[0][0]=grid[0][0];

    for(int i=1; i<m; i++)
    {

        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    for(int i=1; i<n; i++)
    {
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(dp[i][j-1]>=dp[i-1][j])
            {
                dp[i][j]=dp[i-1][j]+grid[i][j];
            }
            else
            {
                dp[i][j]=dp[i][j-1]+grid[i][j];
            }
        }

    }



    return dp[n-1][m-1];

}
int main()
{
    int n,m;
    cin>>n>>m;
    int **grid=new int *[n];
    for(int i=0; i<m; i++)
    {
        grid[i]=new int[m];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }


    cout<< "Minimum Cost : "<<Minimum_Cost_Path(n,m,grid)<<endl;

    return 0;
}
