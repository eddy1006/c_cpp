#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll getNearest(ll x, ll y, ll target) {
   if (target - x >= y - target)
      return y;
   else
      return x;
}
ll getNearestElement(vector<ll> &arr, ll n, ll target) {
   if (target <= arr[0])
      return arr[0];
   if (target >= arr[n - 1])
      return arr[n - 1];
   ll left = 0, right = n, mid = 0;
   while (left < right) {
      mid = (left + right) / 2;
      if (arr[mid] == target)
         return arr[mid];
      if (target < arr[mid]) {
         if (mid > 0 && target > arr[mid - 1])
            return getNearest(arr[mid - 1], arr[mid], target);
            right = mid;
      } else {
         if (mid < n - 1 && target < arr[mid + 1])
            return getNearest(arr[mid], arr[mid + 1], target);
         left = mid + 1;
      }
   }
   return arr[mid];
}
ll up_dwn(vector<ll> &a ,ll n)
{
    ll x;
    if(a[0]>0){
    x = 0;
    ll p =1;
    for(ll i=0;i<n;i++)
    p = p * ((-1)*a[i]);
    if(p>0)
    return 1;
    else
    return 0;}
    else{
    x = a[0] - 50;
    ll p =1;
    for(ll i=0;i<n;i++)
    p = p * (x-a[i]);
    if(p>0)
    return 1;
    else
    return 0;}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;cin>>n>>q;
    vector<ll> vec;
    for(ll i=0;i<n;i++){ll temp;
    cin>>temp; vec.push_back(temp);}
    sort(vec.begin(),vec.end());
    ll direction=up_dwn(vec,n);
    for(ll j=0;j<q;j++)
    {
        ll x;cin>>x;
        if(find(vec.begin(), vec.end(),x)!=vec.end())
        cout<<"0"<<"\n";
        else
        {
          ll near = getNearestElement(vec, n,x);
          vector<ll>:: iterator it;
          it = find(vec.begin(),vec.end(),near);
          ll index = it - vec.begin();
          if(direction==0)
          {
              if(x<vec[index] && (index%2==0))
              cout<<"NEGATIVE\n";
              else if(x<vec[index] && (index%2!=0))
              cout<<"POSITIVE\n";
              else if(x>vec[index] && (index%2==0))
              cout<<"POSITIVE\n";
              else if(x>vec[index] && (index%2!=0))
              cout<<"NEGATIVE\n";
          }
          else 
          {
              if(x<vec[index] && (index%2==0))
              cout<<"POSITIVE\n";
              else if(x<vec[index] && (index%2!=0))
              cout<<"NEGATIVE\n";
              else if(x>vec[index] && (index%2==0))
              cout<<"NEGATIVE\n";
              else if(x>vec[index] && (index%2!=0))
              cout<<"POSITIVE\n";
          }
        }
        
    }
	// your code goes here
	return 0;
}
