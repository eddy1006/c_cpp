#include <bits/stdc++.h>
using namespace std;

vector<string> permutation(string p,string up){
    vector<string> permuts;
    if(up == ""){
        permuts.push_back(p);
        return permuts;
    }else{
      for(int i = 0;i<=p.length();i++){
          vector<string> temp = permutation((p.substr(0,i) + up.substr(0,1) + p.substr(i,p.length()-i)),up.substr(1,up.length()-1));
          for(auto it=temp.begin();it!=temp.end();it++){
              permuts.push_back(*it);
          }
      }
      return permuts;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> permuts = permutation("","vanshi");
    cout<<permuts.size()<<"\n";
    for(auto it = permuts.begin();it!=permuts.end();it++){
        cout<<(*it)<<"\n";
    }
    return 0;
}