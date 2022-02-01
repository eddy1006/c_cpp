#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int base = a;
    int ans = 1 ;
    while(b>0){
        if((b&1) == 1){
            ans = ans*base;
        }
        base = base*base;
        b >>= 1;
    }
    cout<<ans;
    return 0;
}