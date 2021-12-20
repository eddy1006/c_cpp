#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll xa,ya,xb,yb,xc,yc;
        cin>>xa>>ya;
        cin>>xb>>yb;
        cin>>xc>>yc;
        if((xa==xb && xa==xc) || (ya==yb && ya==yc)){
            cout<<"YES\n";
        }
        else if((xa==xb && yb==yc) || (ya==yb &&  xb==xc)){
            cout<<"YES\n";
        }
        else
        cout<<"NO\n";
    }
    return 0;
}