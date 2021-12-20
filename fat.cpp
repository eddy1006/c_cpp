#include<iostream>
#include<utility>
#include<vector>
using namespace std;

bool search_vertical(pair<pair<int,int>,pair<int,int>> &p,vector<pair<pair<int,int>,pair<int,int>>> &v)
{
    vector<pair<pair<int,int>,pair<int,int>>>::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
        if(((*it).first==p.first && (*it).second==p.second)||((*it).second==p.first && (*it).first==p.second))
        return true;
    }
    return false;
}
int main()
{
    int n;cin>>n;int c=0;
    vector<pair<pair<int,int>,pair<int,int>>> vertical;
    vector<pair<pair<int,int>,pair<int,int>>> horizontal;
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
        vertical.push_back(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
        else if(y1==y2)
        horizontal.push_back(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
    }
    vector<pair<pair<int,int>,pair<int,int>>>::iterator it;
    vector<pair<pair<int,int>,pair<int,int>>>::iterator it1;
    for(it=horizontal.begin();it!=horizontal.end();it++)
    {
        for(it1=horizontal.begin();it1!=horizontal.end();it1++)
        {
            if((*it).second.first==(*it1).first.first)
            {
                pair<pair<int,int>,pair<int,int>> pp = make_pair((*it).second,(*it1).first);
                cout<<pp.first.first<<pp.first.second<<pp.second.first<<pp.second.second;
               if(search_vertical(pp,vertical))
               c++;
            }
            if((*it).first.first==(*it1).second.first)
            {
                pair<pair<int,int>,pair<int,int>> pp = make_pair((*it).first,(*it1).second);
                if(search_vertical(pp,vertical))
                c++;
            }
        }
    }
    cout<<c;
}