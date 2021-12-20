#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getsum(string s)
{
    ll sm = 0;
    ll i=1;
    while(i<s.length())
    {
        if(s[i]!=s[i-1])
        sm += 1;
        else
        sm += 2;
        i++;
    }
    return sm;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        string st = "";
        cin>>st;
        ll len = st.length();
        ll sum = getsum(st);
        for(ll i =1;i<=k;i++)
        {
            ll q;
            cin>>q;
            if(st[q-1]=='1')
            st[q-1] = '0';
            else
            st[q-1] = '1';
            if(q!=1 and q!=(len))
            {
                if(st[q-2]==st[q-1])
                sum++;
                else
                sum--;
                if(st[q-1]==st[q])
                sum++;
                else
                sum--;
            }
            else if(q==1)
            {
                if(st[q-1]==st[q])
                sum++;
                else
                sum--;
            }
            else
            {
                if(st[q-2]==st[q-1])
                sum++;
                else
                sum--;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}