#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bs(vector<ll> &v,int d,int n)
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
   if(n==1)
   return high;
   if(n==2)
   return low;
}

