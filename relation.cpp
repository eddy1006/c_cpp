#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,vector<string>>rel;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        for(int j=1;j<=m;j++)
        {
            string one,two;
            cin>>one>>two;
            vector<string> vec;
            vec = rel[one];
            vec.push_back(two);
            rel[one] = vec;
        }
    }
    string query;
    cin>>query;
    vector<string>::iterator itr;
    for(itr=rel[query].begin();itr<=rel[query].end();itr++)
    cout<<(*itr)<<" ";
}