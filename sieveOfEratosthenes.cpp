#include <bits/stdc++.h>
using namespace std;

void eliminate(vector<int>& arr,int num,int limit){
    int i=2;
    while(num*i<= limit){
        arr[num*i]=1;
        i++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n+1,0); 
    int count = 0;
    for(int i=2;i<=n;i++){
        if(arr[i] == 0){
            cout<<i<<"\n";
            count++;
            eliminate(arr,i,n);
        }
    }
    cout<<count;
    return 0;
}