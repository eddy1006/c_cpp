#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n];ll b[n];
        ll min_rem =-1;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
            ll rem = (a[0]+b[i])%n;
            if(min_rem ==-1)
            min_rem == rem;
            else if(rem<min_rem)
            min_rem = rem;
        }
        vector<ll> vec;
        for(ll i=0;i<n;i++){
            ll rem = (a[0]+b[i])%n;
            if(rem == min_rem )
            vec.push_back(i);
        }
        ll index=1;
        while(vec.size()!=1){
            ll min_rem_2 = -1;
            for(auto it=vec.begin();it!=vec.end();it++){
                ll rem = (a[index]+b[(*it)])%n;
                if(min_rem_2 ==-1)
                min_rem_2 == rem;
                else if(rem<min_rem_2)
                min_rem_2 = rem;
            }
            vector<ll> temp = vec;
            vec.clear();
            for(auto it=temp.begin();it!=temp.end();it++){
                ll rem = (a[index]+b[(*it)])%n;
                if(rem == min_rem_2){
                    vec.push_back((*it));
                }
            }
            index++;
        }
        ll var = vec[0];
        for(ll i=0;i<n;i++){
            ll calc = (a[i]+b[var])%n;
            cout<<calc<<" ";
            var = (var+1)%n;
        }
        cout<<"\n";
    }
	// your code goes here
	return 0;
}
