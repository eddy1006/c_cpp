#include<iostream>
#include<list>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    list<string> names;
    list<int> tshirt_no;
    for(int i=1;i<=n;i++)
    {
        int opt;cin>>opt;
        if(opt==1)
        {
            int num;cin>>num;
            while(num--)
            {
                string name;cin>>name;
                names.push_back(name);
            }
        }
        else if(opt==2)
        {
            int m;cin>>m;
            while(m--)
            {
                int no;cin>>no;
                tshirt_no.push_back(no);
            }
        }
        else
        {
            int k;cin>>k;
            while(k--)
            {
                list<string>::iterator it1 = names.begin();
                list<int>::iterator it2 = tshirt_no.end();
                it2--;
                cout<<(*it1)<<" "<<(*it2)<<"\n";
                names.pop_front();
                tshirt_no.pop_back();
            }
        }
    }
}