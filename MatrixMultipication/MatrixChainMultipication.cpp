#include<bits/stdc++.h>
using namespace std;
void MatrixChainMultiplication(int n,int *p)
{
  int m[n][n],s[n][n];
  for(int i=1;i<n;i++ )
  {
      m[i][i]=0;
      s[i][i+1]=i;

  }
  for(int l=2;l<n;l++)
  {
     for(int i=1;i+l-1<n;i++){
        int j=i+l-1,temp=INT_MAX,temp_k=0;
        for(int k=i;k<j;k++)
        {
            int value=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
            if(temp>value)
            {
                temp=value;
                temp_k=k;
            }
        }
        m[i][j]=temp;
        s[i][j]=temp_k;
     }
  }

  cout<<"Matrix Table:"<<"\n";
  for(int i=1;i<n;i++)
  {
      for(int j=1;j<n;j++)
      {
          if(i>j)
          {
              cout<<"-    ";
          }
          else{
            cout<<m[i][j]<<"  ";
          }

      }
       cout<<"\n";
  }
  cout<<"Splitting Table:"<<"\n";
  for(int i=1;i<n;i++)
  {
      for(int j=2;j<n;j++)
      {
          if(i>=j)
          {
              cout<<"-  ";
          }
          else{
            cout<<s[i][j]<<"  ";
          }

      }
        cout<<"\n";
  }

  cout<<"Minimum Scalar Operation in Matrix Chain :"<<m[1][n-1]<<"\n";

}

int main()
{
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
   MatrixChainMultiplication(n,p);

    return 0;
}
