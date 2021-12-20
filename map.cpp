#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void)
{
   map<string,int> marks;
   marks["Eddy"]= 49;
   marks["Dawg"]= 41;
   marks["Pussy"] = 30;
    map<string,int> :: iterator it;
    for(it = marks.begin();it!=marks.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    marks.insert({{"Shit",40},{"Ass",25}});
    for(it = marks.begin();it!=marks.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}