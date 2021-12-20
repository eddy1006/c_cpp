#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    map<ll,ll> arrival; map<ll,ll> departure;
    set<ll> times;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        times.insert(a);
        times.insert(b);
        arrival[a]++;
        departure[b]++;
    }
    vector<ll> room_count;ll room_empty = 1;
    for(auto x: times){
        if(arrival[x]){ 
            if(room_empty>0)
            room_empty = room_empty - arrival[x];
            else
            room_count+= arrival[x];
        }
        if(departure[x]){
            room_empty+= departure[x];
        }
    }    
    cout<<room_count.size()<<"\n";
}

