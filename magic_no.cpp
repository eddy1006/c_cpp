//find the nth magic number

// magic nos : 1 :- 001 - 5^1 = 5
//             2 :- 010 - 5^2 = 25
//             3 :- 011 - 5^2 +5^1 = 30

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int ans= 0;
  int base = 5;
  while(n > 0 ){
      int last = n & 1;
      ans += last * base;
      base = base*5;
      n = n>> 1;
  }
  cout<<ans;
  return 0;
}