#include <iostream>
using namespace std;

int check(int* a,int n)
{
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[n])
        count++;
    }
    if(count>0)
    return 0;
    else 
    return 1;
}
int counter(int* a,int n,int m)
{
    int count =0;
    for(int i=n;i<m;i++)
    {
        if(a[i]==a[n])
        count++;
    }
    return count;
}
int main() {
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int n,w,w_r;
        cin>>n>>w>>w_r;
        int a[n];
        for(int y=0;y<n;y++)
        cin>>a[y];
        int s=w_r;int br=0;
        for(int i=0;i<n;i++)
        {
            if(check(a,i))
            {
                int c = counter(a,i,n);
                if(c%2==0)
                s = s+ (c*a[i]);
                else 
                s = s + ((c-1)*a[i]);
            }
            if(s>=w)
            {
                br=1;
                break;
            }
        }
        if(br==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
	// your code goes here
	return 0;
}