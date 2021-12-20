#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    map<int,int> m1;
    map<int,vector<int>> m2;
    for(int j=0;j<n;j++)
    {
        for(int k=j+1;k<n;k++)
        { 
            if(m1[abs(a[j]-a[k])]<(j+1)){
            m1[abs(a[j]-a[k])]+=1;
            vector<int> vec;
            vec = m2[abs(a[j]-a[k])];
            vec.push_back(a[j]);
            m2[abs(a[j]-a[k])] = vec;}
        }
    }
    map<int,int>::iterator it;
    int maxval;int max =0;
    for(it=m1.begin();it!=m1.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<"\n";
        if(max==0){
        max = (*it).second;
        maxval = (*it).first;}
        else 
        {
            if((*it).second>max)
            {
               max = (*it).second;
               maxval = (*it).first;
            }
        }
    }
    vector<int>::iterator itr;
    sort(m2[maxval].begin(),m2[maxval].end());
    for(itr=m2[maxval].begin();itr<m2[maxval].end();itr++)
    cout<<(*itr)<<" ";
}