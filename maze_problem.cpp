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

//function for if we also allow diagonal travel
void path_diag(string p,int r,int c){
    if(r == 1 && c==1){
        cout<<p<<endl;
        return;
    }else{
        if( r >1 && c>1 )
            path_diag(p+"dg",r-1,c-1);
        if( r > 1)
            path_diag(p+"R",r-1,c);
        if( c> 1)
            path_diag(p+"D",r,c-1);
    }
}

//finding path when starting from 1,1 and also with few obstacles in the maze

void path_restrictions(string p,vector<vector<bool>> maze,int r,int c){
    if(r == maze.size()-1 && c==maze[0].size() - 1){
        cout<<p<<endl;
        return;
    }else{
        if(!maze[r][c])
            return;
        if( r < maze.size()-1)
            path_restrictions(p+"R",maze,r+1,c);
        if( c <maze[0].size()-1)
            path_restrictions(p+"D",maze,r,c+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<bool>> vec( 3,vector<bool> (3,true));
    vec[1][1] = false; // obstacle
    //cout<<count(3,3)<<endl;
    //path("",3,3);
    //path_diag("",3,3);
    path_restrictions("",vec,0,0); // all paths from 1,1 to 3,3 with 2,2 as obstacle
    return 0;
}