#include<iostream> 
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,mc;
    cin>>n;cin>>mc;
    vector<string> names;
    vector<vector<int>> coins;
    for(int i=0;i<n;i++)
    {
        string name;
        cin>>name;
        names.push_back(name);
        vector<int> vec;
        for(int j=0;j<mc;j++){int temp; cin>>temp;
        vec.push_back(temp);}
        coins.push_back(vec);
    }
    int k;cin>>k;
    vector<string>::iterator it1;
    vector<string>::iterator it2;
    for(int x=1;x<=k;x++)
    {
        string name1,name2;
        cin>>name1>>name2;
        it1 = find(names.begin(),names.end(),name1);
        it2 = find(names.begin(),names.end(),name2);
        int index1 = it1 - names.begin();
        int index2 = it2 - names.begin();
        coins[index1].swap(coins[index2]);
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<names[i]<<" ";
        vector<int>::iterator itr;
        for(itr=coins[i].begin();itr!=coins[i].end();itr++)
        cout<<(*itr)<<" ";
        cout<<"\n";
    }
}

/*#include<iostream> 
#include<map>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,mc;
    cin>>n;cin>>mc;
    map<string,vector<int>> m;
    for(int i=1;i<=n;i++)
    {
        string name;
        cin>>name; 
        vector<int> coins;
        for(int j=0;j<mc;j++){int temp; cin>>temp;
        coins.push_back(temp);}
        m[name] = coins;
    }
    int k;cin>>k;
    for(int x=1;x<=k;x++)
    {
        string name1,name2;
        cin>>name1>>name2;
        m[name1].swap(m[name2]);
    }
    map<string,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" ";
        vector<int> vc;
        vc = (*it).second;
        for(int itr=0;itr<mc;itr++)
        cout<<vc[itr]<<" ";
        cout<<"\n";
    }
}
*/