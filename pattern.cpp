#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 1;i<=4;i++){
       int j=4;int t = i;
       while(t-1> 0){
       cout<<j-- <<" ";t--;}
       for(int k=j;k>=1;k++)
       cout<<j<<" ";
       for(int t=1;t<=j;t++)
       cout<<j<<" ";
       t=i;
       while(t-1 > 0 ){
       cout<<++j<<" ";t--;}
       cout<<"\n";
    }
    return 0;
}