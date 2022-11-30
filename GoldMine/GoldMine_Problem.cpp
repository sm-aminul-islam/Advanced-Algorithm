#include<bits/stdc++.h>
using namespace std;
bool valid(int x,int y,int n,int m)
{
    return x>=0 && x<n && y>=0 &&y<m;
}
int  Goldmine(int n,int m,int **grid)
{
    pair<int,int > loc= {-1,-1};
    int ans=0;
    int dp[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dp[i][j]=0;
        }
    }


    for(int i=0; i<n; i++)
    {
        dp[i][0]=grid[i][0];
    }
    for(int j=1; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            int x=0,y=0,z=0;
            if(valid(i-1,j-1,n,m))
            {
                x=dp[i-1][j-1];
            }
            if(valid(i,j-1,n,m))
            {
                y=dp[i][j-1];
            }
            if(valid(i+1,j-1,n,m))
            {
                z=dp[i+1][j-1];
            }
            dp[i][j]=grid[i][j]+max({x,y,z});
            if(j==m-1 && ans<=dp[i][j])
            {

                ans=dp[i][j];
                loc= {i,j};
            }

        }
    }

    cout<<loc.first<<" "<<loc.second<<"\n";



    return ans;

}

int main()
{
    int n,m;
    cin>>n>>m;
    int **grid=new int*[n];
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
    cout<<Goldmine(n,m,grid)<<"\n";
    return 0;
}
