#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll a[n];
    map<ll,pair<ll,ll>> m1;
    ll arr[q];
    for(ll i=0;i<n;i++){cin>>a[i];}
    for(ll k=0;k<q;k++)
    {
        ll query;
        cin>>query;
        if(query==1)
        {
            ll l,r,x;
            for(ll j=l-1;j<r;j++)
            {
               m1[j] = make_pair(l,x);
            }
            arr[k]= -1;
        }
        else
        {
            ll y;cin>>y;
            arr[k] = y;
        }
    }
    for
