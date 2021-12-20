#include<iostream>
#include<string.h>
using namespace std;

int check(char* s)
{
    int i=0;int count = 0;
    while(s[i])
    {
        count++;
        i++;
    }
    return count;
}
void change_string(char* w,char* t2,int i,int j)
{
    int t=0;
    for(int k=i;k<=j;k++)
    {
        w[k] = t2[t];
        t++;
    }
}
int derivable(char* w,char* w2,char* t,char* t2,int c)
{
    char str[c];
    int i=0;int j=c-1;
    while(w[i+j])
    {
        int temp=0;
        for(int k=i;k<=j;k++)
        {
            str[temp] = w[k];
            temp++;
        }
        if(strcmp(str,t)==0){
        change_string(w,t2,i,j);i=0; j= c-1;}
        else
        {
            i++;j++;
        }
        if(strcmp(w,w2)==0)
        {
            return 1;
            break;
        }
    }
    return 0;
}
int main(void)
{
    char w[20];char w2[20];
    char t[20];char t2[20];
    cin>>w;
    cin>>w2;
    cin>>t;
    cin>>t2;
    int c = check(t);
    if(derivable(w,w2,t,t2,c))
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}
