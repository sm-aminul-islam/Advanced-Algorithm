#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    cin>>n>>m;
    vector<int >ans;
    while(n>0)
    {

        int sum=ceil((double)m/n);
        cout<<sum<<endl;
        ans.push_back(sum);
        n=n*sum-m;
        m=m*sum;

    }
    for(auto x:ans)
    {
        cout<<"1/"<<x<<" ";
    }
    return 0;
}
