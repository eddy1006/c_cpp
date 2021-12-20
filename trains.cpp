#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bs(vector<ll> &v,ll d,int n)
{
   ll low = 0;
   ll high = v.size()-1;
   ll mid ;
   if(n==1 && d<v[low])
   return -1;
   if(n==2 && d>v[high])
   return -1;
   while(low<=high)
   {
       mid = (low+high)/2;
       if(v[mid]==d)
       return mid;
       else if(v[mid]>d)
       high = mid-1;
       else
       low = mid+1;
   }
   cout<<low<<high<<endl;
   if(n==1)
   return high;
   else if(n==2)
   return low;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        vector<ll> trains1;
        vector<ll> trains2;
        ll n,m,temp,dest;
        cin>>n>>m;
        for(ll i=1;i<=n;i++)
        {
            cin>>temp;
            if(temp==1)
            trains1.push_back(i);
            else if(temp==2)
            trains2.push_back(i);
        }
        for(ll j=1;j<=m;j++)
        {
           ll dest;
           cin>>dest;
           ll one; one= bs(trains1,dest,1);
           ll two; two = bs(trains2,dest,2);
           cout<<one<<two;
           /*if(one==-1 && two==-1){
               cout<<"-1 ";
            }
            if(one==-1)
            {
                cout<<abs(trains2[two]-dest);
            }
            else if(two==-1)
            {
                cout<<abs(trains1[one]-dest);
            }
            else if(trains1[one]==dest || trains2[two]==dest)
            {
                cout<<"0 ";
            }
            else
            cout<<min(abs(trains1[one]-dest),abs(trains2[two]-dest));*/
        }
        cout<<"\n";
    }
    return 0;
}