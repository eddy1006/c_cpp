#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,string> m1;
    map<string,string> m2;
    int n;cin>>n;
    string name;
    string symbol;
    for(int i=1;i<=n;i++)
    {
        cin>>name>>symbol;
        m1[symbol] = name;
        m2[name] = symbol;
    }
    int query_type;cin>>query_type;
    string find; cin>>find;
    if(query_type==1)
    {
      if(m1.count(find))
      cout<<m1[find];
      else
      cout<<"Not found";
    }
    else 
    {
        if(m2.count(find))
        cout<<m2[find];
        else
        cout<<"Not found";
    }
}