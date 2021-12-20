#include<iostream>
using namespace std;

int main(void)
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int l;int count =0;int br=0;
        cin>>l;
        char s[l];
        cin>>s;
        for(int i=0;i<l;i++)
        {
           if(s[i]=='1')
           count++;
          if(i>0)
          {
              if((i+1)%2==0)
              {
                  if(count>=((i+1)/2))
                  {
                      br=1;
                      break;
                  }
              }
              else 
              {
                  if(count>((i+1)/2))
                  {
                      br=1;
                      break;
                  }
              }
          }
          else
          {
              if(count>0)
              {
                  br =1;
                  break;
              }
          }
        }
        if(br==1)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
    return 0;
}