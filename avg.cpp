#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long arr[k];
        for(long long i =0;i<k;i++){
            cin>>arr[i];
        }
        sort(arr,arr+k);
        long long i = k-1;
        long long cat_location = 0;
        long long ans = 0;
        while(arr[i]>cat_location){
            cat_location = cat_location + (n-arr[i]);
            i--;
            ans++; 
        }
        cout<<ans<<"\n";
    }
    return 0;
}