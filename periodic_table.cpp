#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(void)
{
    map<int,map<string,vector<string>>> m;
    for(int i=1;i<=2;i++)
    {
        vector<string> vec;
        string name,symbol,group,block,atomic_no,state;
        cin>>name>>symbol>>group>>block>>atomic_no>>state;
        vec.push_back(name);
        vec.push_back(group);
        vec.push_back(block);
        vec.push_back(atomic_no);
        vec.push_back(state);
        m[1][symbol] = vec;
    }
    int j=2;
    for(int i=1;i<=30;i++)
    {
       vector<string> vec;
        string name,symbol,group,block,atomic_no,state;
        cin>>name>>symbol>>group>>block>>atomic_no>>state;
        vec.push_back(name);
        vec.push_back(group);
        vec.push_back(block);
        vec.push_back(atomic_no);
        vec.push_back(state);
        m[j][symbol] = vec;
        if(i%5==0)
        j++;
    }
    int period;
    string symb;
    cin>>period>>symb;
    for(int k=0;k<5;k++)
    {
      cout<<m[period][symb][k]<<" ";
    }
}