#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bs(vector<ll> &v,int d)
{
   ll low = 0;
   ll high = v.size()-1;
   ll mid ;
   while(low<=high)
   {
       mid = (low+high)/2;
       if(v[mid]==d)
       break;
       else if(v[mid]>d)
       high = mid-1;
       else
       low = mid+1;
   }
   cout<<low<<mid<<high<<endl;
   return -1;
}
int main()
{
    vector<ll> vec;
    while(true){ ll temp; cin>>temp;if(temp==-1)break; vec.push_back(temp);}
    cout<<bs(vec,4);
}