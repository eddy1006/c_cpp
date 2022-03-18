#include <bits/stdc++.h>
using namespace std;

double findSqrt(double n){
    double x = n;
    double root;
    while(true){
        root = 0.5 *(x + (n/x));
        if(abs(root-x) < 0.5){
            break;
        }
        x = root;
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n;
    cin>>n;
    cout<<findSqrt(n);
    return 0;
}