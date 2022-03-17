
//Finding square root of a number without using the in built function.

#include <bits/stdc++.h>
using namespace std;

double findSqrt(int n,int precision){
    double root = 0.0;
    int start = 0;
    int end = n;
    while(start<=end){
        int middle = start + (end - start)/2;
        if(middle*middle == n)
            return middle;
        if(middle*middle < n)
            start = middle + 1;
        else    
            end = middle - 1;
        root = middle -1;
    }
    double increment = 0.1;
    for(int i=1;i<=precision;i++){
        while(root*root < n){
            root += increment;
        }
        root -= increment;
        increment /= 10;
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<findSqrt(n,3);  //3 means till precision 3,  
    return 0;
}
