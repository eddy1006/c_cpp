// The no of ways by which we can reach to a specific co-ordinate in a matrix if we can move only right and down.
#include <bits/stdc++.h>
using namespace std;

int count(int r,int c){
    if(r == 1 || c==1)
        return 1;
    else{
        int opt1 = count(r-1,c);
        int opt2 = count(r,c-1);
        return opt1 + opt2;
    }
}

void path(string pt,int r,int c){
    if(r == 1 && c==1){
        cout<<pt<<"\n";
         return;
    }else if(r == 1){
        path(pt+"D",r,c-1);
    }else if(c == 1){
        path(pt+"R",r-1,c);
    }
    else{
        path(pt+"D",r,c-1);
        path(pt+"R",r-1,c);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<count(3,3)<<endl;
    path("",3,3);
    return 0;
}