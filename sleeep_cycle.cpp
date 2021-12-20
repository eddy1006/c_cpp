#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,h;
        cin>>l>>h;
        string s;cin>>s;
        ll i=0;
        ll counter = 0;
        ll free_no = 0;
        ll index=-1;
        map<ll,ll, greater<ll>> m ;
        while(i<l)
        {
            if(s[i]=='1')
            {
                index = -1;
                if(counter!=0)
                m[counter] = free_no;
                counter=0;
            }
            if(s[i]=='0')
            {
                if(index==-1)
                {
                    index = i;
                    counter++;
                    free_no++;
                }
                else{
                    counter++;
                } 
            }
            i++;
        }
        if(counter!=0)
        m[counter]=free_no;
        ll ahead = 0;
        map<ll,ll>::iterator it=m.begin();
        while(it!=m.end())
        {
            if(ahead==0)
            {
                ahead = (*it).second;
                if((*it).first>=h)
                break;
                h = h - (*it).first;
                h = 2*h;
            }
            else if((*it).second>ahead)
            {
                ahead = (*it).second;
                if((*it).first>=h)
                break;
                h = h - (*it).first;
                h = 2*h;
            }
            it++;
        }
        if(it==m.end())
        cout<<"NO"<<"\n";
        else 
        cout<<"YES"<<"\n";
    }
	// your code goes here
	return 0;
}
