#include<iostream>
#include<utility>
#include<vector>
using namespace std;
pair<int,int> nm;
void make_moves1(vector<pair<int,int>> &v, pair<int,int> &p,int len)
{
    pair<int,int> p1(p);
    pair<int,int> p2(p);
    if(p.first<nm.first){
    p1.first = p.first+1;
      v.push_back(p1);}
    if(p.second<nm.second){
    p2.second = p.second + 1;
    v.push_back(p2);}
    
}
void make_moves2(vector<pair<int,int>> &v, pair<int,int> &p)
{
    pair<int,int> p1(p);
    pair<int,int> p2(p);
    pair<int,int> p3(p);
    if(p.first<nm.first){
    p1.first = p.first+1;
      v.push_back(p1);}
    if(p.second<nm.second){
    p2.second = p.second + 1;
    v.push_back(p2);}
    if(p.first<nm.first && p.second<nm.second)
    {
        p3.first = p.first +1;
        p3.second = p.second +1;
        v.push_back(p3);
    }
}
void create_moves(vector<pair<int,int>> &v,int n)
{
    int l= v.size();
   for(int i=0;i<l;i++)
   {
       if(n==1)
       make_moves1(v,v[i],l);
       else
       make_moves2(v,v[i]);
   }
   if(n==1)
   v.erase(v.begin(),v.begin()+l);
} 
int compare(vector<pair<int,int>> &v1,vector<pair<int,int>> &v2)
{
    for(int i=0;i<v2.size();i++)
    {
        if(v2[i]==nm)
        return 1;
        for(int j=0;j<v1.size();j++)
        {
            if(v2[i]==v1[j])
            return 1;
            if(v1[j] == nm)
            return 2;
        }
       
    }
    return 0;
}
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        pair<int,int> thief;
        pair<int,int> police;
        cin>>nm.first>>nm.second;
        cin>>thief.first>>thief.second;
        cin>>police.first>>police.second;
        vector<pair<int,int>> thief_moves;
        vector<pair<int,int>> police_moves;
        thief_moves.push_back(thief);
        police_moves.push_back(police);
        int i=1;int c;
        while(true)
        {
            if(i%2!=0)
            {
                create_moves(thief_moves,1);
            }
            else{
                create_moves(police_moves,2);
            }
            c = compare(thief_moves,police_moves);
            if(c==1 || c==2)
            break;
            i++;
        }
        if(c==1)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
}