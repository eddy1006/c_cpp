#include <bits/stdc++.h>
using namespace std;


//Time Complexity O(n)
void factors(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0)
        cout<<i<<" ";
    }
    cout<<"\n";
}


//Time complexity O(sqrt(n))
void factors2(int n){
    vector<int> secondHalf;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            if(n/i == i){   //basic idea is if i is a factor of n then n/i will obviously be its factor so no need to check above sqrt of number.
                cout<<i<<" ";
            }else{
                cout<<i<<" ";
                secondHalf.push_back(n/i);
            }
        }
    }
    for(auto itr = secondHalf.rbegin();itr!=secondHalf.rend();itr++){
        cout<<(*itr)<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    factors(n);
    factors2(n);
    return 0;
}