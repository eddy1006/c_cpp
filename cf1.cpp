#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
int main()
{
    ll t;cin>>t;
    while(t--)
    {
       ll n,k;
       cin>>n>>k;
       ll a[n];
       map<ll,ll> count;
       map<ll,ll> color;
       map<ll,ll> idk;
       ll counter = 0;
       for(ll i=0;i<n;i++){
           cin>>a[i];
           count[a[i]]++;
           if(count[a[i]]>k)
           counter++;
       }
       ll share = (n-counter)/k;
       for(ll j=0;j<n;j++){
           if(idk[a[j]]==0){
               idk[a[j]] = k;
               if(color[idk[a[k]]]<=share){
               cout<<idk[a[j]]<<" ";
               color[idk[a[k]]]++;}
           }
           else{
               idk[a[j]]--;
               if(color[idk[a[k]]]<=share){
               cout<<idk[a[j]]<<" ";
               color[idk[a[k]]]++;}
           }
       }
    }
}