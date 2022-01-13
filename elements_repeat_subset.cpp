#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> outer;
    outer.push_back({});
    int arr[] ={1,2,2};
    int start = 0;
    int end = 0;
    for(int i =0;i<3;i++){
        start =0;
        if( i> 0  && arr[i] == arr[i-1]){
            start = end +1;
        }
        end = outer.size() -1;
        for(int j = start;j<=end;j++){
            vector<int> inner(outer[j]);
            inner.push_back(arr[i]);
            outer.push_back(inner);
        }
    }
    for(auto it =outer.begin();it!=outer.end();it++){
        for(auto itr = (*it).begin();itr != (*it).end();itr++){
            cout<<(*itr)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}