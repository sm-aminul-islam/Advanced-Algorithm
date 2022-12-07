#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    s+='$';
    int n=s.size();
    s+=s;
    vector<string> st;
    for(int i=0;i<n;i++)
    {
       string temp=s.substr(i,n);
       st.push_back(temp);

    }
    sort(st.begin(),st.end());
    for(auto x: st)
    {
        cout<<x<<endl;

    }
    string p;
    for(auto y:st)
    {

        p+=y[y.size()-1];

    }
    cout<<"Burrow's Wheeler Transform:"<<p<<"\n";

    return 0;
}
