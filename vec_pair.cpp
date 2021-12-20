#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
void bubbleSort(vector<pair<ll,string>> &v, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
    {
        for (j = 0; j < n-i-1; j++){
            if (v[j].first > v[j+1].first)
                swap(v[j], v[j+1]);
            else if(v[j].first==v[j+1].first)
            {
                if(int(v[j].second[0])>int(v[j+1].second[0]))
                    swap(v[j],v[j+1]);
            }  
         }
    }
}
int main()
{
    vector<pair<ll,string>> vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll num;string color;
        cin>>num>>color;
        vec.push_back(make_pair(num,color));
    }
    bubbleSort(vec,n);
    ll index;
    cin>>index;
    cout<<vec[index-1].first<<" "<<vec[index-1].second;
}
